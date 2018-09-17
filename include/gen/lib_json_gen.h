//
// include/gen/lib_json_gen.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/algo_gen.h"
//#pragma endinclude

// --- lib_json_FNode_type_Enum

enum lib_json_FNode_type_Enum {        // lib_json.FNode.type
     lib_json_FNode_type_null     = 0
    ,lib_json_FNode_type_false    = 1
    ,lib_json_FNode_type_true     = 2
    ,lib_json_FNode_type_string   = 3
    ,lib_json_FNode_type_number   = 4
    ,lib_json_FNode_type_array    = 5
    ,lib_json_FNode_type_object   = 6
    ,lib_json_FNode_type_field    = 7
};

enum { lib_json_FNode_type_Enum_N = 8 };


// --- lib_json_FParser_state_Enum

enum lib_json_FParser_state_Enum {              // lib_json.FParser.state
     lib_json_FParser_state_ws           = 0
    ,lib_json_FParser_state_value        = 1
    ,lib_json_FParser_state_number       = 2
    ,lib_json_FParser_state_str          = 3
    ,lib_json_FParser_state_str_esc      = 4
    ,lib_json_FParser_state_str_uesc     = 5
    ,lib_json_FParser_state_str_usurr1   = 6
    ,lib_json_FParser_state_str_usurr2   = 7
    ,lib_json_FParser_state_token        = 8
    ,lib_json_FParser_state_sec_line     = 9    // JSON security line
    ,lib_json_FParser_state_err          = 99   // parser error
};

enum { lib_json_FParser_state_Enum_N = 11 };


// --- lib_json_FieldIdEnum

enum lib_json_FieldIdEnum {        // lib_json.FieldId.value
     lib_json_FieldId_value   = 0
};

enum { lib_json_FieldIdEnum_N = 1 };

namespace lib_json { struct FNode; }
namespace lib_json { struct trace; }
namespace lib_json { struct FDb; }
namespace lib_json { struct FldKey; }
namespace lib_json { struct FParser; }
namespace lib_json { struct FieldId; }
namespace lib_json { struct _db_ind_objfld_curs; }
namespace lib_json { struct node_c_child_curs; }
namespace lib_json {
}//pkey typedefs
namespace lib_json {
struct lpool_Lpblock {
    lpool_Lpblock* next;
};
extern FDb _db;

// --- lib_json.trace
#pragma pack(push,1)
struct trace { // lib_json.trace
    u64   alloc__db_node;   //   0
    u64   del__db_node;     //   0
    trace();
};
#pragma pack(pop)

// Set all fields to initial values.
void                 trace_Init(lib_json::trace& parent);
// print string representation of lib_json::trace to string LHS, no header -- cprint:lib_json.trace.String
void                 trace_Print(lib_json::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- lib_json.FDb
// create: lib_json.FDb._db (Global)
struct FDb { // lib_json.FDb
    lpool_Lpblock*      lpool_free[31];             // Lpool levels
    u32                 node_blocksize;             // # bytes per block
    lib_json::FNode*    node_free;                  //
    lib_json::FNode**   ind_objfld_buckets_elems;   // pointer to bucket array
    i32                 ind_objfld_buckets_n;       // number of elements in bucket array
    i32                 ind_objfld_n;               // number of elements in the hash table
    lib_json::trace     trace;                      //
};

// Free block of memory previously returned by Lpool.
void                 lpool_FreeMem(void *mem, u64 size) __attribute__((nothrow));
// Allocate new piece of memory at least SIZE bytes long.
// If not successful, return NULL
// The allocated block is 16-byte aligned
void*                lpool_AllocMem(u64 size) __attribute__((__warn_unused_result__, nothrow));
// Add N buffers of some size to the free store
bool                 lpool_ReserveBuffers(int nbuf, u64 bufsize) __attribute__((nothrow));
// Allocate new block, copy old to new, delete old.
// New memory is always allocated (i.e. size reduction is not a no-op)
// If no memory, return NULL: old memory untouched
void*                lpool_ReallocMem(void *oldmem, u64 old_size, u64 new_size) __attribute__((nothrow));

void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
bool                 LoadTuplesMaybe(algo::strptr root) __attribute__((nothrow));
// Load specified ssimfile.
bool                 LoadSsimfileMaybe(algo::strptr fname) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
lib_json::FNode&     node_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
lib_json::FNode*     node_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Remove row from all global and cross indices, then deallocate row
void                 node_Delete(lib_json::FNode &row) __attribute__((nothrow));
// Allocate space for one element
// If no memory available, return NULL.
void*                node_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Remove mem from all global and cross indices, then deallocate mem
void                 node_FreeMem(lib_json::FNode &row) __attribute__((nothrow));
// Preallocate memory for N more elements
// Return number of elements actually reserved.
u64                  node_Reserve(u64 n_elems) __attribute__((nothrow));
// Allocate block of given size, break up into small elements and append to free list.
// Return number of elements reserved.
u64                  node_ReserveMem(u64 size) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 node_XrefMaybe(lib_json::FNode &row);

// Return true if hash is empty
bool                 ind_objfld_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
lib_json::FNode*     ind_objfld_Find(const lib_json::FldKey& key) __attribute__((__warn_unused_result__, nothrow));
// Return number of items in the hash
i32                  ind_objfld_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_objfld_InsertMaybe(lib_json::FNode& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_objfld_Remove(lib_json::FNode& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_objfld_Reserve(int n) __attribute__((nothrow));

bool                 JsonNumCharQ(u32 ch) __attribute__((nothrow));

bool                 JsonFirstNumCharQ(u32 ch) __attribute__((nothrow));

// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- lib_json.FldKey
struct FldKey { // lib_json.FldKey
    lib_json::FNode*   object;   // optional pointer
    algo::strptr       field;    //
    explicit FldKey(lib_json::FNode*               in_object
        ,algo::strptr                   in_field);
    bool operator ==(const lib_json::FldKey &rhs) const;
    bool operator <(const lib_json::FldKey &rhs) const;
    FldKey();
};

u32                  FldKey_Hash(u32 prev, const lib_json::FldKey & rhs) __attribute__((nothrow));
bool                 FldKey_Lt(lib_json::FldKey & lhs, lib_json::FldKey & rhs) __attribute__((nothrow));
i32                  FldKey_Cmp(lib_json::FldKey & lhs, lib_json::FldKey & rhs) __attribute__((nothrow));
// Set all fields to initial values.
void                 FldKey_Init(lib_json::FldKey& parent);
bool                 FldKey_Eq(const lib_json::FldKey & lhs,const lib_json::FldKey & rhs) __attribute__((nothrow));
// Set value. Return true if new value is different from old value.
bool                 FldKey_Update(lib_json::FldKey &lhs, lib_json::FldKey & rhs) __attribute__((nothrow));
// print string representation of lib_json::FldKey to string LHS, no header -- cprint:lib_json.FldKey.String
void                 FldKey_Print(lib_json::FldKey & row, algo::cstring &str) __attribute__((nothrow));

// --- lib_json.FNode
// create: lib_json.FDb.node (Tpool)
// global access: ind_objfld (Thash)
// access: lib_json.FNode.p_parent (Upptr)
// access: lib_json.FNode.c_child (Ptrary)
// access: lib_json.FParser.node (Ptr)
// access: lib_json.FParser.root_node (Ptr)
// access: lib_json.FldKey.object (Ptr)
struct FNode { // lib_json.FNode
    lib_json::FNode*    node_next;             // Pointer to next free element int tpool
    lib_json::FNode*    ind_objfld_next;       // hash next
    lib_json::FNode*    p_parent;              // reference to parent row
    lib_json::FNode**   c_child_elems;         // array of pointers
    u32                 c_child_n;             // array of pointers
    u32                 c_child_max;           // capacity of allocated array
    u32                 type;                  //   0
    algo::cstring       value;                 //
    bool                node_c_child_in_ary;   //   false  membership flag
private:
    friend lib_json::FNode&     node_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend lib_json::FNode*     node_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 node_Delete(lib_json::FNode &row) __attribute__((nothrow));
    FNode();
    ~FNode();
    FNode(const FNode&){ /*disallow copy constructor */}
    void operator =(const FNode&){ /*disallow direct assignment */}
};

// Delete all elements pointed to by the index.
void                 c_child_Cascdel(lib_json::FNode& node) __attribute__((nothrow));
// Return true if index is empty
bool                 c_child_EmptyQ(lib_json::FNode& node) __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
lib_json::FNode*     c_child_Find(lib_json::FNode& node, u32 t) __attribute__((__warn_unused_result__, nothrow));
// Return array of pointers
algo::aryptr<lib_json::FNode*> c_child_Getary(lib_json::FNode& node) __attribute__((nothrow));
// Insert pointer to row into array. Row must not already be in array.
// If pointer is already in the array, it may be inserted twice.
void                 c_child_Insert(lib_json::FNode& node, lib_json::FNode& row) __attribute__((nothrow));
// Insert pointer to row in array.
// If row is already in the array, do nothing.
// Return value: whether element was inserted into array.
bool                 c_child_InsertMaybe(lib_json::FNode& node, lib_json::FNode& row) __attribute__((nothrow));
// Return number of items in the pointer array
i32                  c_child_N(const lib_json::FNode& node) __attribute__((__warn_unused_result__, nothrow, pure));
// Find element using linear scan. If element is in array, remove, otherwise do nothing
void                 c_child_Remove(lib_json::FNode& node, lib_json::FNode& row) __attribute__((nothrow));
// Empty the index. (The rows are not deleted)
void                 c_child_RemoveAll(lib_json::FNode& node) __attribute__((nothrow));
// Reserve space in index for N more elements;
void                 c_child_Reserve(lib_json::FNode& node, u32 n) __attribute__((nothrow));

// Get value of field as enum type
lib_json_FNode_type_Enum type_GetEnum(const lib_json::FNode& node) __attribute__((nothrow));
// Set value of field from enum type.
void                 type_SetEnum(lib_json::FNode& node, lib_json_FNode_type_Enum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          type_ToCstr(const lib_json::FNode& node) __attribute__((nothrow));
// Convert type to a string. First, attempt conversion to a known string.
// If no string matches, print type as a numeric value.
void                 type_Print(const lib_json::FNode& node, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 type_SetStrptrMaybe(lib_json::FNode& node, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 type_SetStrptr(lib_json::FNode& node, algo::strptr rhs, lib_json_FNode_type_Enum dflt) __attribute__((nothrow));

lib_json::FldKey     fldkey_Get(lib_json::FNode& node) __attribute__((__warn_unused_result__, nothrow));
void                 fldkey_Set(lib_json::FNode& node, const lib_json::FldKey& rhs) __attribute__((nothrow));

// Set all fields to initial values.
void                 FNode_Init(lib_json::FNode& node);
void                 node_c_child_curs_Reset(node_c_child_curs &curs, lib_json::FNode &parent);
// cursor points to valid item
bool                 node_c_child_curs_ValidQ(node_c_child_curs &curs);
// proceed to next item
void                 node_c_child_curs_Next(node_c_child_curs &curs);
// item access
lib_json::FNode&     node_c_child_curs_Access(node_c_child_curs &curs);
void                 FNode_Uninit(lib_json::FNode& node) __attribute__((nothrow));
// print string representation of lib_json::FNode to string LHS, no header -- cprint:lib_json.FNode.String
void                 FNode_Print(lib_json::FNode & row, algo::cstring &str) __attribute__((nothrow));

// --- lib_json.FParser
struct FParser { // lib_json.FParser
    algo::strptr       buf;          //
    i32                ind;          //   0
    lib_json::FNode*   node;         // optional pointer
    lib_json::FNode*   root_node;    // optional pointer
    u32                state;        //   0
    bool               need_comma;   //   false
    bool               have_comma;   //   false
    bool               need_colon;   //   false
    algo::cstring      err_info;     //
    i32                err_offset;   //   0
    i32                offset;       //   0
    u32                uesc_value;   //   0
    u8                 uesc_need;    //   0
    algo::cstring      value;        //
    FParser();
    ~FParser();
private:
    // user-defined fcleanup on lib_json.FParser.root_node prevents copy
    FParser(const FParser&){ /*disallow copy constructor */}
    void operator =(const FParser&){ /*disallow direct assignment */}
};

// User-defined cleanup function invoked for field root_node of lib_json::FParser
void                 root_node_Cleanup(lib_json::FParser& parent) __attribute__((nothrow));

// Get value of field as enum type
lib_json_FParser_state_Enum state_GetEnum(const lib_json::FParser& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 state_SetEnum(lib_json::FParser& parent, lib_json_FParser_state_Enum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          state_ToCstr(const lib_json::FParser& parent) __attribute__((nothrow));
// Convert state to a string. First, attempt conversion to a known string.
// If no string matches, print state as a numeric value.
void                 state_Print(const lib_json::FParser& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 state_SetStrptrMaybe(lib_json::FParser& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 state_SetStrptr(lib_json::FParser& parent, algo::strptr rhs, lib_json_FParser_state_Enum dflt) __attribute__((nothrow));

// Set all fields to initial values.
void                 FParser_Init(lib_json::FParser& parent);
void                 FParser_Uninit(lib_json::FParser& parent) __attribute__((nothrow));
// print string representation of lib_json::FParser to string LHS, no header -- cprint:lib_json.FParser.String
void                 FParser_Print(lib_json::FParser & row, algo::cstring &str) __attribute__((nothrow));

// --- lib_json.FieldId
#pragma pack(push,1)
struct FieldId { // lib_json.FieldId: Field read helper
    i32   value;   //   -1
    inline operator lib_json_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(lib_json_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
lib_json_FieldIdEnum value_GetEnum(const lib_json::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(lib_json::FieldId& parent, lib_json_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const lib_json::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const lib_json::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(lib_json::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(lib_json::FieldId& parent, algo::strptr rhs, lib_json_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(lib_json::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of lib_json::FieldId from an ascii string.
// The format of the string is the format of the lib_json::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(lib_json::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(lib_json::FieldId& parent);
// print string representation of lib_json::FieldId to string LHS, no header -- cprint:lib_json.FieldId.String
void                 FieldId_Print(lib_json::FieldId & row, algo::cstring &str) __attribute__((nothrow));

struct node_c_child_curs {// cursor
    typedef lib_json::FNode ChildType;
    lib_json::FNode** elems;
    u32 n_elems;
    u32 index;
    node_c_child_curs() { elems=NULL; n_elems=0; index=0; }
};

} // end namespace lib_json
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const lib_json::trace &row);// cfmt:lib_json.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_json::FldKey &row);// cfmt:lib_json.FldKey.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_json::FNode &row);// cfmt:lib_json.FNode.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_json::FParser &row);// cfmt:lib_json.FParser.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_json::FieldId &row);// cfmt:lib_json.FieldId.String
}