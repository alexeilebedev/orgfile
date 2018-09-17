//
// include/gen/report_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
inline report::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline report::FieldId::FieldId(report_FieldIdEnum arg) { this->value = i32(arg); }
inline report::FieldId::FieldId() {
    report::FieldId_Init(*this);
}


// --- report.FieldId.value.GetEnum
// Get value of field as enum type
inline report_FieldIdEnum report::value_GetEnum(const report::FieldId& parent) {
    return report_FieldIdEnum(parent.value);
}

// --- report.FieldId.value.SetEnum
// Set value of field from enum type.
inline void report::value_SetEnum(report::FieldId& parent, report_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- report.FieldId.value.Cast
inline report::FieldId::operator report_FieldIdEnum () const {
    return report_FieldIdEnum((*this).value);
}

// --- report.FieldId..Init
// Set all fields to initial values.
inline void report::FieldId_Init(report::FieldId& parent) {
    parent.value = i32(-1);
}
inline report::Protocol::Protocol() {
}

inline report::abt::abt(u16                            in_n_target
        ,algo::UnDiff                   in_time
        ,u32                            in_n_warn
        ,u32                            in_n_err
        ,u16                            in_n_install)
    : n_target(in_n_target)
    , time(in_time)
    , n_warn(in_n_warn)
    , n_err(in_n_err)
    , n_install(in_n_install)
{
}
inline report::abt::abt() {
    report::abt_Init(*this);
}


// --- report.abt..Init
// Set all fields to initial values.
inline void report::abt_Init(report::abt& parent) {
    parent.n_target = u16(0);
    parent.n_warn = u32(0);
    parent.n_err = u32(0);
    parent.n_install = u16(0);
}
inline report::acr::acr() {
    report::acr_Init(*this);
}


// --- report.acr..Init
// Set all fields to initial values.
inline void report::acr_Init(report::acr& parent) {
    parent.n_select = u32(0);
    parent.n_insert = u32(0);
    parent.n_delete = u32(0);
    parent.n_update = u32(0);
    parent.n_file_mod = u32(0);
}
inline report::acr_check::acr_check(u32                            in_records
        ,u32                            in_errors)
    : records(in_records)
    , errors(in_errors)
{
}
inline report::acr_check::acr_check() {
    report::acr_check_Init(*this);
}


// --- report.acr_check..Init
// Set all fields to initial values.
inline void report::acr_check_Init(report::acr_check& parent) {
    parent.records = u32(0);
    parent.errors = u32(0);
}
inline report::amc::amc() {
    report::amc_Init(*this);
}


// --- report.amc..Init
// Set all fields to initial values.
inline void report::amc_Init(report::amc& parent) {
    parent.n_cppfile = u32(0);
    parent.n_cppline = u32(0);
    parent.n_ctype = u32(0);
    parent.n_func = u32(0);
    parent.n_xref = u32(0);
    parent.n_filemod = u32(0);
}
inline report::atf_unit::atf_unit() {
    report::atf_unit_Init(*this);
}


// --- report.atf_unit..Init
// Set all fields to initial values.
inline void report::atf_unit_Init(report::atf_unit& parent) {
    parent.n_test_total = u32(0);
    parent.n_test_run = u64(0);
    parent.n_test_step = u64(0);
    parent.n_cmp = u64(0);
    parent.n_err = u64(0);
}
inline report::src_func::src_func() {
    report::src_func_Init(*this);
}


// --- report.src_func..Init
// Set all fields to initial values.
inline void report::src_func_Init(report::src_func& parent) {
    parent.n_func = u32(0);
    parent.n_line = u32(0);
    parent.n_static = u32(0);
    parent.n_inline = u32(0);
    parent.n_mysteryfunc = u32(0);
    parent.n_filemod = u32(0);
    parent.n_baddecl = u32(0);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::FieldId &row) {// cfmt:report.FieldId.String
    report::FieldId_Print(const_cast<report::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::abt &row) {// cfmt:report.abt.String
    report::abt_Print(const_cast<report::abt&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::acr &row) {// cfmt:report.acr.String
    report::acr_Print(const_cast<report::acr&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::acr_check &row) {// cfmt:report.acr_check.String
    report::acr_check_Print(const_cast<report::acr_check&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::amc &row) {// cfmt:report.amc.String
    report::amc_Print(const_cast<report::amc&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::atf_unit &row) {// cfmt:report.atf_unit.String
    report::atf_unit_Print(const_cast<report::atf_unit&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::src_func &row) {// cfmt:report.src_func.String
    report::src_func_Print(const_cast<report::src_func&>(row), str);
    return str;
}