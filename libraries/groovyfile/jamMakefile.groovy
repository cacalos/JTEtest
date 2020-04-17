
String call(){

	def contents = '''
UNITTEST_PATH := $(dir ${UNITTEST})
UNITTEST_AOUT := $(notdir ${UNITTEST})

REQUIRED_DIRS = reports reports/unittest reports/coverage
_MKDIRS := $(shell for d in $(REQUIRED_DIRS); \
             do                               \
               [[ -d $$d ]] || mkdir -p $$d;  \
             done)

.PHONY: all build clean coverage lint unittest help
all: build

$(CONFIGURE_PATH)/config.status.build:
	cd $(CONFIGURE_PATH) && ./configure $(CONFIGURE_OPTION) && cp $(CONFIGURE_PATH)/config.status $(CONFIGURE_PATH)/config.status.build

$(CONFIGURE_PATH)/config.status.cov:
	export CFLAGS=--coverage && export LDFLAGS=--coverage && export LIBS=-lgcov && cd $(CONFIGURE_PATH) && ./configure $(CONFIGURE_OPTION) && sed -i &quot;s/--no-whole-archive/--no-whole-archive -lgcov/g&quot; Jamfile.sys && cp $(CONFIGURE_PATH)/config.status $(CONFIGURE_PATH)/config.status.cov

$(UNITTEST_PATH)/$(UNITTEST_AOUT): $(CONFIGURE_PATH)/config.status.cov build.coverage
	cd $(UNITTEST_PATH) && jam clean && jam -dx
$(BUILD_HOME)/reports/unittest/report.xml: $(UNITTEST_PATH)/$(UNITTEST_AOUT)
	$(UNITTEST_PATH)/$(UNITTEST_AOUT) 2>&1 > $(BUILD_HOME)/reports/unittest/report.xml
	
unittest: $(BUILD_HOME)/reports/unittest/report.xml ;

clean: ## clean files TODO NEED TO VALIDATE
	${CLEAN_SCRIPT_LIST} || true
	jam clean
	cd $(UNITTEST_PATH) && jam clean
	rm -rf reports || true
	rm build* || true
	rm $(CONFIGURE_PATH)/config.status* || true

$(BUILD_HOME)/reports/coverage/report.xml: $(BUILD_HOME)/reports/unittest/report.xml
	cd $(BUILD_HOME) && gcovr -r . --xml-pretty > $(BUILD_HOME)/reports/coverage/report.xml

coverage: $(BUILD_HOME)/reports/coverage/report.xml ;

$(BUILD_HOME)/reports/rawcppcheck.xml: $(CONFIGURE_PATH)/config.status.build
	cppcheck --force --inconclusive --xml --xml-version=2 . 2> $(BUILD_HOME)/reports/rawcppcheck.xml
$(BUILD_HOME)/reports/clang.txt: $(CONFIGURE_PATH)/config.status.build
	@jam check  2> $(BUILD_HOME)/reports/clang.txt || true
$(BUILD_HOME)/reports/cppcheck.xml: $(BUILD_HOME)/reports/rawcppcheck.xml $(BUILD_HOME)/reports/clang.txt
	python $(BUILD_HOME)/cvtclang.py  $(BUILD_HOME)/reports/rawcppcheck.xml $(BUILD_HOME)/reports/clang.txt 1> $(BUILD_HOME)/reports/cppcheck.xml

lint: $(BUILD_HOME)/reports/cppcheck.xml ;

build.coverage: $(CONFIGURE_PATH)/config.status.cov
	cd $(BUILD_HOME) && jam clean && jam -dx install && touch build.coverage
build.done: $(CONFIGURE_PATH)/config.status.build ## Build the binary file
	@cd $(BUILD_HOME) && jam clean && jam -dx install && touch build.done
build: build.done

image: ## make docker image
	$(MAKEIMAGE_SHELL)
'''
	return contents.replace("&quot;", "\"")
}
