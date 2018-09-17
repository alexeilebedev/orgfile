//
// include/gen/report_gen.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/algo_gen.h"
//#pragma endinclude

// --- report_FieldIdEnum

enum report_FieldIdEnum {                 // report.FieldId.value
     report_FieldId_n_target        = 0
    ,report_FieldId_time            = 1
    ,report_FieldId_n_warn          = 2
    ,report_FieldId_n_err           = 3
    ,report_FieldId_n_install       = 4
    ,report_FieldId_n_select        = 5
    ,report_FieldId_n_insert        = 6
    ,report_FieldId_n_delete        = 7
    ,report_FieldId_n_update        = 8
    ,report_FieldId_n_file_mod      = 9
    ,report_FieldId_records         = 10
    ,report_FieldId_errors          = 11
    ,report_FieldId_n_cppfile       = 12
    ,report_FieldId_n_cppline       = 13
    ,report_FieldId_n_ctype         = 14
    ,report_FieldId_n_func          = 15
    ,report_FieldId_n_xref          = 16
    ,report_FieldId_n_filemod       = 17
    ,report_FieldId_n_test_total    = 18
    ,report_FieldId_n_test_run      = 19
    ,report_FieldId_n_test_step     = 20
    ,report_FieldId_n_cmp           = 21
    ,report_FieldId_n_line          = 22
    ,report_FieldId_n_static        = 23
    ,report_FieldId_n_inline        = 24
    ,report_FieldId_n_mysteryfunc   = 25
    ,report_FieldId_n_baddecl       = 26
    ,report_FieldId_comment         = 27
    ,report_FieldId_value           = 28
};

enum { report_FieldIdEnum_N = 29 };

namespace report { struct FieldId; }
namespace report { struct Protocol; }
namespace report { struct abt; }
namespace report { struct acr; }
namespace report { struct acr_check; }
namespace report { struct amc; }
namespace report { struct atf_unit; }
namespace report { struct src_func; }
namespace report {
}//pkey typedefs
namespace report {

// --- report.FieldId
#pragma pack(push,1)
struct FieldId { // report.FieldId: Field read helper
    i32   value;   //   -1
    inline operator report_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(report_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
report_FieldIdEnum   value_GetEnum(const report::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(report::FieldId& parent, report_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const report::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const report::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(report::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(report::FieldId& parent, algo::strptr rhs, report_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(report::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of report::FieldId from an ascii string.
// The format of the string is the format of the report::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(report::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(report::FieldId& parent);
// print string representation of report::FieldId to string LHS, no header -- cprint:report.FieldId.String
void                 FieldId_Print(report::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- report.Protocol
// access: report.Protocol.proto (Protocol)
#pragma pack(push,1)
struct Protocol { // report.Protocol: amc-generated struct for internal purposes
    Protocol();
};
#pragma pack(pop)

void                 StaticCheck();


// --- report.abt
struct abt { // report.abt
    u16            n_target;    //   0
    algo::UnDiff   time;        //
    u32            n_warn;      //   0
    u32            n_err;       //   0
    u16            n_install;   //   0
    explicit abt(u16                            in_n_target
        ,algo::UnDiff                   in_time
        ,u32                            in_n_warn
        ,u32                            in_n_err
        ,u16                            in_n_install);
    abt();
};

bool                 abt_ReadFieldMaybe(report::abt &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of report::abt from an ascii string.
// The format of the string is an ssim Tuple
bool                 abt_ReadStrptrMaybe(report::abt &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 abt_Init(report::abt& parent);
// print string representation of report::abt to string LHS, no header -- cprint:report.abt.String
void                 abt_Print(report::abt & row, algo::cstring &str) __attribute__((nothrow));

// --- report.acr
struct acr { // report.acr
    u32   n_select;     //   0
    u32   n_insert;     //   0
    u32   n_delete;     //   0
    u32   n_update;     //   0
    u32   n_file_mod;   //   0
    acr();
};

bool                 acr_ReadFieldMaybe(report::acr &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of report::acr from an ascii string.
// The format of the string is an ssim Tuple
bool                 acr_ReadStrptrMaybe(report::acr &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 acr_Init(report::acr& parent);
// print string representation of report::acr to string LHS, no header -- cprint:report.acr.String
void                 acr_Print(report::acr & row, algo::cstring &str) __attribute__((nothrow));

// --- report.acr_check
struct acr_check { // report.acr_check
    u32   records;   //   0  Number of records checked
    u32   errors;    //   0  Number of errors reported
    explicit acr_check(u32                            in_records
        ,u32                            in_errors);
    acr_check();
};

bool                 acr_check_ReadFieldMaybe(report::acr_check &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of report::acr_check from an ascii string.
// The format of the string is an ssim Tuple
bool                 acr_check_ReadStrptrMaybe(report::acr_check &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 acr_check_Init(report::acr_check& parent);
// print string representation of report::acr_check to string LHS, no header -- cprint:report.acr_check.String
void                 acr_check_Print(report::acr_check & row, algo::cstring &str) __attribute__((nothrow));

// --- report.amc
struct amc { // report.amc
    u32   n_cppfile;   //   0
    u32   n_cppline;   //   0
    u32   n_ctype;     //   0
    u32   n_func;      //   0
    u32   n_xref;      //   0
    u32   n_filemod;   //   0
    amc();
};

bool                 amc_ReadFieldMaybe(report::amc &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of report::amc from an ascii string.
// The format of the string is an ssim Tuple
bool                 amc_ReadStrptrMaybe(report::amc &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 amc_Init(report::amc& parent);
// print string representation of report::amc to string LHS, no header -- cprint:report.amc.String
void                 amc_Print(report::amc & row, algo::cstring &str) __attribute__((nothrow));

// --- report.atf_unit
struct atf_unit { // report.atf_unit
    u32   n_test_total;   //   0
    u64   n_test_run;     //   0
    u64   n_test_step;    //   0
    u64   n_cmp;          //   0
    u64   n_err;          //   0
    atf_unit();
};

bool                 atf_unit_ReadFieldMaybe(report::atf_unit &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of report::atf_unit from an ascii string.
// The format of the string is an ssim Tuple
bool                 atf_unit_ReadStrptrMaybe(report::atf_unit &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 atf_unit_Init(report::atf_unit& parent);
// print string representation of report::atf_unit to string LHS, no header -- cprint:report.atf_unit.String
void                 atf_unit_Print(report::atf_unit & row, algo::cstring &str) __attribute__((nothrow));

// --- report.src_func
struct src_func { // report.src_func
    u32             n_func;          //   0
    u32             n_line;          //   0
    u32             n_static;        //   0
    u32             n_inline;        //   0
    u32             n_mysteryfunc;   //   0
    u32             n_filemod;       //   0
    u32             n_baddecl;       //   0
    algo::Comment   comment;         //
    src_func();
};

bool                 src_func_ReadFieldMaybe(report::src_func &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of report::src_func from an ascii string.
// The format of the string is an ssim Tuple
bool                 src_func_ReadStrptrMaybe(report::src_func &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 src_func_Init(report::src_func& parent);
// print string representation of report::src_func to string LHS, no header -- cprint:report.src_func.String
void                 src_func_Print(report::src_func & row, algo::cstring &str) __attribute__((nothrow));
} // end namespace report
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const report::FieldId &row);// cfmt:report.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const report::abt &row);// cfmt:report.abt.String
inline algo::cstring &operator <<(algo::cstring &str, const report::acr &row);// cfmt:report.acr.String
inline algo::cstring &operator <<(algo::cstring &str, const report::acr_check &row);// cfmt:report.acr_check.String
inline algo::cstring &operator <<(algo::cstring &str, const report::amc &row);// cfmt:report.amc.String
inline algo::cstring &operator <<(algo::cstring &str, const report::atf_unit &row);// cfmt:report.atf_unit.String
inline algo::cstring &operator <<(algo::cstring &str, const report::src_func &row);// cfmt:report.src_func.String
}