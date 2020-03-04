#ifndef RPDU_ERROR_H
#define RPDU_ERROR_H

#define RP_UNASSIGNED_NUMBER					0x01 /* O,   1   Unassigned (unallocated) number */
#define RP_OPERATOR_DETERMINED_BARRING			0x08 /* O,   8   Operator determined barring */
#define RP_CALL_BARRED							0x0A /* O,   10  Call barred */
#define RP_RESERVED								0x0B /* O,   11  Reserved */
#define RP_SM_TRANSFER_REJECTED					0x15 /* O,   21  Short message transfer rejected */
#define RP_MEMORY_CAPACITY_EXCEEDED				0x16 /* T,   22  Memory capacity exceeded */
#define RP_DESTINATION_OUT_OF_ORDER				0x1B /* O,   27  Destination out of order */
#define RP_UNIDENTIFIED_SUBSCRIBER				0X1C /* O,   28  Unidentified subscriber */
#define RP_FACILITY_REJECTED					0x1D /* O,   29  Facility rejected */
#define RP_UNKNOWN_SUBSCRIBER					0x1E /* O,   30  Unknown subscriber */
#define RP_NETWORK_OUT_OF_ORDER					0x26 /* O,   38  Network out of order */
#define RP_TEMPORARY_FAILURE					0x29 /* O,   41  Temporary failure */
#define RP_CONGESTION							0x2A /* O,   42  Congestion */
#define RP_RESOURCES_UNAVAILABLE				0x2F /* O,   47  Resources unavailable, unspecified */
#define RP_REQUESTED_FACILITY_NOT_SUBSCRIBE		0x32 /* O,   50  Requested facility not subscribed */
#define RP_REQUESTED_FACILITY_NOT_IMPLEMENTED	0x45 /* O,   69  Requested facility not implemented */
#define RP_INVALID_SM_TRANSFER_REFERENCE_VALUE	0x51 /* O,T, 81  Invalid short message transfer reference value */
#define RP_SEMANTICALLY_INCORRECT_MESSAGE		0x5F /* O,T, 95  Semantically incorrect message */
#define RP_INVALID_MANDATORY_INFORMATION		0x60 /* O,T, 96  Invalid mandatory information */
#define RP_MESSAGE_TYPE_NON_EXISTENT			0x61 /* O,T, 97  Message type non-existent or not implemented */
#define RP_MESSAGE_NOT_COMPATIBLE				0x62 /* O,T, 98  Message not compatible with short message protocol state */
#define RP_INFORMATION_ELEMENT_NON_EXISTENT		0x63 /* O,T, 99  Information element non-existent or not implemented */
#define RP_PROTOCOL_ERROR_UNSPECIFIED			0x6F /* O,T, 111 Protocol error, unspecified */
#define RP_INTERWORKING_UNSPECIFIED				0x7F /* O,   127 Interworking, unspecified */

#define RPDU_ERROR_STR(s) \
	( s == RP_UNASSIGNED_NUMBER					? "RP_UNASSIGNED_NUMBER" :\
		s == RP_OPERATOR_DETERMINED_BARRING			? "RP_OPERATOR_DETERMINED_BARRING" :\
		s == RP_CALL_BARRED							? "RP_CALL_BARRED" :\
		s == RP_RESERVED							? "RP_RESERVED	" :\
		s == RP_SM_TRANSFER_REJECTED				? "RP_SM_TRANSFER_REJECTED" :\
		s == RP_MEMORY_CAPACITY_EXCEEDED			? "RP_MEMORY_CAPACITY_EXCEEDED" :\
		s == RP_DESTINATION_OUT_OF_ORDER			? "RP_DESTINATION_OUT_OF_ORDER" :\
		s == RP_UNIDENTIFIED_SUBSCRIBER				? "RP_UNIDENTIFIED_SUBSCRIBER" :\
		s == RP_FACILITY_REJECTED				    ? "RP_FACILITY_REJECTED" :\
		s == RP_UNKNOWN_SUBSCRIBER		            ? "RP_UNKNOWN_SUBSCRIBER" :\
		s == RP_NETWORK_OUT_OF_ORDER				? "RP_NETWORK_OUT_OF_ORDER" :\
		s == RP_TEMPORARY_FAILURE					? "RP_TEMPORARY_FAILURE" :\
		s == RP_CONGESTION							? "RP_CONGESTION" :\
		s == RP_RESOURCES_UNAVAILABLE               ? "RP_RESOURCES_UNAVAILABLE" :\
		s == RP_REQUESTED_FACILITY_NOT_SUBSCRIBE	? "RP_REQUESTED_FACILITY_NOT_SUBSCRIBE" :\
		s == RP_REQUESTED_FACILITY_NOT_IMPLEMENTED	? "RP_REQUESTED_FACILITY_NOT_IMPLEMENTED" :\
		s == RP_INVALID_SM_TRANSFER_REFERENCE_VALUE	? "RP_INVALID_SM_TRANSFER_REFERENCE_VALUE" :\
		s == RP_SEMANTICALLY_INCORRECT_MESSAGE		? "RP_SEMANTICALLY_INCORRECT_MESSAGE" :\
		s == RP_INVALID_MANDATORY_INFORMATION		? "RP_INVALID_MANDATORY_INFORMATION" :\
		s == RP_MESSAGE_TYPE_NON_EXISTENT			? "RP_MESSAGE_TYPE_NON_EXISTENT" :\
		s == RP_MESSAGE_NOT_COMPATIBLE				? "RP_MESSAGE_NOT_COMPATIBLE" :\
		s == RP_INFORMATION_ELEMENT_NON_EXISTENT	? "RP_INFORMATION_ELEMENT_NON_EXISTENT" :\
		s == RP_PROTOCOL_ERROR_UNSPECIFIED			? "RP_PROTOCOL_ERROR_UNSPECIFIED" :\
		s == RP_INTERWORKING_UNSPECIFIED			? "RP_INTERWORKING_UNSPECIFIED" : "UNKNOWN ERROR")

#endif
