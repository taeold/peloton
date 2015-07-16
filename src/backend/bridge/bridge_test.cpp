/*-------------------------------------------------------------------------
 *
 * bridge_test.cpp
 * file description
 *
 * Copyright(c) 2015, CMU

 * /peloton/tests/bridge/bridge_test.cpp
 *
 *-------------------------------------------------------------------------
 */

#include "bridge_test.h"


#include "backend/bridge/bridge.h"
#include "backend/bridge/ddl.h"
#include "backend/storage/database.h"

namespace peloton {
namespace test {

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

/**
 * @brief Test "DDL::CreateTable" function
 *        with various test cases
 */
void BridgeTest::DDL_CreateTable_TEST() {

  DDL_CreateTable_TEST_INVALID_OID();
  DDL_CreateTable_TEST_COLUMNS();
  DDL_CreateTable_TEST_COLUMN_CONSTRAINTS();

}

/**
 * @brief CreateTable with INVALID OID
 *        It MUST return false 
 */
void BridgeTest::DDL_CreateTable_TEST_INVALID_OID() {

<<<<<<< HEAD
  // ColumnInfo
  std::vector<catalog::Column> columns;

  bool status = bridge::DDL::CreateTable( INVALID_OID, "test_table_invalid_oid", columns );
=======
  // Empty ColumnInfo
  std::vector<catalog::ColumnInfo> column_infos;

  // Table name and oid
  std::string table_name = "test_table_invalid_oid";
  oid_t table_oid = INVALID_OID;

  // Create a table
  bool status = bridge::DDL::CreateTable( table_oid, table_name, column_infos );

  // CHECK :: status must be false
>>>>>>> bridge
  assert( status == false );

<<<<<<< HEAD
void BridgeTest::DDL_CreateTable_TEST_COLUMNS() {

  storage::Database* db = storage::Database::GetDatabaseById( GetCurrentDatabaseOid() );
=======
  printf( COLOR_GREEN ":::::: %s DONE" COLOR_RESET "\n", __func__ );
}
>>>>>>> bridge

/**
 * @brief Create a simple ColumnInfo just for convenience 
 * @return the vector of ColumnInfo
 */
std::vector<catalog::ColumnInfo> BridgeTest::CreateSimpleColumns()
{
  // ColumnInfo
  std::vector<catalog::Column> columns;

  catalog::Column column1( VALUE_TYPE_INTEGER, 4, "id");
  catalog::Column column2( VALUE_TYPE_VARCHAR, 68, "name");
  catalog::Column column3( VALUE_TYPE_TIMESTAMP, 8, "time");
  catalog::Column column4( VALUE_TYPE_DOUBLE, 8, "salary");

  columns.push_back(column1);
  columns.push_back(column2);
  columns.push_back(column3);
  columns.push_back(column4);

<<<<<<< HEAD
  bool status = bridge::DDL::CreateTable( 20000, "test_table_basic_column", columns );
  assert( status );
=======
  return column_infos;
}
>>>>>>> bridge

/**
 * @brief Create a table with simple Columns
 */
void BridgeTest::DDL_CreateTable_TEST_COLUMNS() {
 
  storage::Database* db = storage::Database::GetDatabaseById( GetCurrentDatabaseOid() );

  // Get the simple columns
  std::vector<catalog::ColumnInfo> column_infos = CreateSimpleColumns();

  // Table name and oid
  std::string table_name = "test_table_basic_columns";
  oid_t table_oid = 20001;

  // Create a table
  bool status = bridge::DDL::CreateTable( table_oid, table_name, column_infos );
  assert ( status );

  // Get the table pointer
  storage::DataTable* table = db->GetTableById(table_oid);

  // TODO::CHECK :: Table name and oid
  assert( strcmp( (table->GetName()).c_str(), table_name.c_str()) == 0 );
  assert( table->GetId() == table_oid );

  // Get the table's schema to get a column 
  catalog::Schema* schema = table->GetSchema();

  std::cout << (*schema);

  // The first column
  catalog::Column column = schema->GetColumn(0);

  // TODO::CHECK ::  Column name, length, type
  assert( strcmp( column.GetName().c_str(), "id" ) == 0 );
  assert( column.GetLength() == 4 );
  assert( column.GetType() == VALUE_TYPE_INTEGER );

  // The second column
  column = schema->GetColumn(1);

  // TODO::CHECK ::  Column name, length, type
  assert( strcmp( column.GetName().c_str(), "name" ) == 0 );
  assert( column.GetLength() == 68 );
  assert( column.GetType() == VALUE_TYPE_VARCHAR );

  // The third column
  column = schema->GetColumn(2);

  // TODO::CHECK ::  Column name, length, type
  assert( strcmp( column.GetName().c_str(), "time" ) == 0 );
  assert( column.GetLength() == 8 );
  assert( column.GetType() == VALUE_TYPE_TIMESTAMP );

  // The fourth column
  column = schema->GetColumn(3);

  // TODO::CHECK ::  Column name, length, type
  assert( strcmp( column.GetName().c_str(), "salary" ) == 0 );
  assert( column.GetLength() == 8 );
  assert( column.GetType() == VALUE_TYPE_DOUBLE );

  printf( COLOR_GREEN ":::::: %s DONE" COLOR_RESET "\n", __func__ );
}

/**
 * @brief Create a table with simple columns that contain
 *        column-level constraints such as single column 
 *        primary key, unique, and reference table 
 */
void BridgeTest::DDL_CreateTable_TEST_COLUMN_CONSTRAINTS() {

  storage::Database* db = storage::Database::GetDatabaseById( GetCurrentDatabaseOid() );

<<<<<<< HEAD
  // constraints
  std::vector<catalog::Constraint> constraints;

  // constraint
  catalog::Constraint notnull_constraint( CONSTRAINT_TYPE_NOTNULL );
  catalog::Constraint primary_key_constraint( CONSTRAINT_TYPE_PRIMARY, "THIS_IS_PRIMARY_KEY_CONSTRAINT" );
  catalog::Constraint unique_constraint( CONSTRAINT_TYPE_UNIQUE, "THIS_IS_UNIQUE_CONSTRAINT" );
  catalog::Constraint foreign_constraint( CONSTRAINT_TYPE_FOREIGN, "THIS_IS_FOREIGN_CONSTRAINT" );


  // ColumnInfo
  std::vector<catalog::Column> columns;

  catalog::Column column1( VALUE_TYPE_INTEGER, 4, "id");
  column1.AddConstraint(notnull_constraint);

  catalog::Column column2( VALUE_TYPE_VARCHAR, 68, "name");
  column2.AddConstraint(primary_key_constraint);

  catalog::Column column3( VALUE_TYPE_TIMESTAMP, 8, "time");
  column3.AddConstraint(unique_constraint);

  catalog::Column column4( VALUE_TYPE_DOUBLE, 8, "salary");
  column4.AddConstraint(foreign_constraint);

  columns.push_back(column1);
  columns.push_back(column2);
  columns.push_back(column3);
  columns.push_back(column4);

  // Create a table
  bool status = bridge::DDL::CreateTable( 20001, "test_table_notnull_constraint", columns );
=======
  // Get the simple columns
  std::vector<catalog::ColumnInfo> column_infos = CreateSimpleColumns();

  // Table name and oid
  std::string table_name = "test_table_column_constraint";
  oid_t table_oid = 20002;

  // Create a table
  bool status = bridge::DDL::CreateTable( table_oid, table_name, column_infos );
  assert ( status );

  // Get the table pointer and schema
  storage::DataTable* table = db->GetTableById(table_oid);
  catalog::Schema *schema = table->GetSchema();

  // Create the constrains
  catalog::Constraint *notnull_constraint = new catalog::Constraint( CONSTRAINT_TYPE_NOTNULL );
  catalog::Constraint *primary_key_constraint = new catalog::Constraint( CONSTRAINT_TYPE_PRIMARY, "THIS_IS_PRIMARY_KEY_CONSTRAINT" );
  catalog::Constraint *unique_constraint = new catalog::Constraint( CONSTRAINT_TYPE_UNIQUE, "THIS_IS_UNIQUE_CONSTRAINT" );

  // Add one constraint to the one column
  schema->AddConstraintByColumnName( "id",    notnull_constraint );
  schema->AddConstraintByColumnName( "name",  primary_key_constraint );
  schema->AddConstraintByColumnName( "time",  unique_constraint );

  // Create a primary key index
  // NOTE:: It must be called automatically in active or bootstrap mode
  std::vector<std::string> key_column_names;
  key_column_names.push_back("name");
  bridge::IndexInfo* index_info = new bridge::IndexInfo( "THIS_IS_PRIMARY_KEY_CONSTRAINT",
                                                          30001,
                                                          table_name,
                                                          INDEX_METHOD_TYPE_BTREE_MULTIMAP,
                                                          INDEX_TYPE_PRIMARY_KEY,
                                                          true,
                                                          key_column_names);
  status = bridge::DDL::CreateIndex( *index_info );
  assert( status );

  // Create a unique index
  key_column_names.clear();
  key_column_names.push_back("time");
  index_info = new bridge::IndexInfo( "THIS_IS_UNIQUE_CONSTRAINT",
                                       30002,
                                       table_name,
                                       INDEX_METHOD_TYPE_BTREE_MULTIMAP,
                                       INDEX_TYPE_UNIQUE,
                                       true,
                                       key_column_names);

  status = bridge::DDL::CreateIndex( *index_info );
  assert( status );

  // Create a reference table that will be referenced by another table
  std::string pktable_name = "pktable";
  oid_t pktable_oid = 20003;
  status = bridge::DDL::CreateTable( pktable_oid, pktable_name, column_infos );
>>>>>>> bridge
  assert ( status );

  // Construct ReferenceTableInfo
  std::vector<std::string> pk_column_names;
  std::vector<std::string> fk_column_names;
  pk_column_names.push_back("name");
  fk_column_names.push_back("salary");
  std::vector<catalog::ReferenceTableInfo> reference_table_infos;
  catalog::ReferenceTableInfo *reference_table_info = new catalog::ReferenceTableInfo( pktable_oid,
                                                                                       pk_column_names,
                                                                                       fk_column_names,
                                                                                       'r',
                                                                                       'c',
                                                                                       "THIS_IS_FOREIGN_CONSTRAINT");
  reference_table_infos.push_back( *reference_table_info );

  // Current table ----> reference table
  status = peloton::bridge::DDL::SetReferenceTables( reference_table_infos, table_oid );
  assert ( status );


  // TODO::CHECK :: check only regarding constraint. Skip others, such as, column name, length, etc.

  // The first column
<<<<<<< HEAD
  catalog::Column column = schema->GetColumn(0);

  // Column name, offset, length, type, constraint not null
  assert( strcmp( column.GetName().c_str(), "id" ) == 0 );
  assert( column.GetOffset() == 0 );
  assert( column.GetLength() == 4 );
  assert( column.GetType() == VALUE_TYPE_INTEGER );

  constraints.clear();
  constraints = column.GetConstraints();
  assert( constraints.size() == 1 );
  ConstraintType type = constraints[0].GetType();
  assert( type == CONSTRAINT_TYPE_NOTNULL );


  // The second column
  column = schema->GetColumn(1);
=======
  // TODO::CHECK :: Not null constraint type 
  catalog::ColumnInfo column = schema->GetColumnInfo(0);
  std::vector<catalog::Constraint> constraint_infos = column.GetConstraints();
  assert( constraint_infos[0].GetType() == CONSTRAINT_TYPE_NOTNULL );

  // The second column
  // TODO::CHECK :: Primary key constraint type, name
  column = schema->GetColumnInfo(1);
  constraint_infos = column.GetConstraints();
  assert( constraint_infos[0].GetType() == CONSTRAINT_TYPE_PRIMARY );
  assert( strcmp( constraint_infos[0].GetName().c_str(), "THIS_IS_PRIMARY_KEY_CONSTRAINT") == 0 );
>>>>>>> bridge

  // TODO::CHECK :: the primary key index name, type, etc.
  index::Index *index = table->GetIndexByOid( 30001 );
  assert( strcmp(index->GetName().c_str(), "THIS_IS_PRIMARY_KEY_CONSTRAINT") == 0 );
  assert(  index->GetColumnCount() == 1 );
  assert ( index->GetIndexMethodType()   == INDEX_METHOD_TYPE_BTREE_MULTIMAP);
  assert ( index->GetIndexType() == INDEX_TYPE_PRIMARY_KEY);
  assert ( index->HasUniqueKeys()  == true);

<<<<<<< HEAD
  constraints.clear();
  constraints = column.GetConstraints();
  assert( constraints.size() == 1 );
  type = constraints[0].GetType();
  assert( type == CONSTRAINT_TYPE_PRIMARY );
  std::string name = constraints[0].GetName();
  assert( strcmp( name.c_str(), "THIS_IS_PRIMARY_KEY_CONSTRAINT") == 0 );

  // The third column
  column = schema->GetColumn(2);

  // Column name, offset, length, type, constraint not null
  assert( strcmp( column.GetName().c_str(), "time" ) == 0 );
  assert( column.GetOffset() == 72 );
  assert( column.GetLength() == 8 );
  assert( column.GetType() == VALUE_TYPE_TIMESTAMP );

  constraints.clear();
  constraints = column.GetConstraints();
  assert( constraints.size() == 1 );
  type = constraints[0].GetType();
  assert( type == CONSTRAINT_TYPE_UNIQUE );
  name = constraints[0].GetName();
  assert( strcmp( name.c_str(), "THIS_IS_UNIQUE_CONSTRAINT") == 0 );
=======

  // The third column
  // TODO::CHECK :: Unique constraint name, type, etc.
  column = schema->GetColumnInfo(2);
  constraint_infos = column.GetConstraints();
  assert( constraint_infos[0].GetType() == CONSTRAINT_TYPE_UNIQUE );
  assert( strcmp( constraint_infos[0].GetName().c_str(), "THIS_IS_UNIQUE_CONSTRAINT") == 0 );
>>>>>>> bridge

  // TODO::Check  index for unique constraint
  index = table->GetIndexByOid( 30002 );
  assert( strcmp(index->GetName().c_str(), "THIS_IS_UNIQUE_CONSTRAINT") == 0 );
  assert(  index->GetColumnCount() == 1 );
  assert ( index->GetIndexMethodType()   == INDEX_METHOD_TYPE_BTREE_MULTIMAP);
  assert ( index->GetIndexType() == INDEX_TYPE_UNIQUE);
  assert ( index->HasUniqueKeys()  == true);

  // The fourth column
<<<<<<< HEAD
  column = schema->GetColumn(3);

  // Column name, offset, length, type, constraint not null
  assert( strcmp( column.GetName().c_str(), "salary" ) == 0 );
  assert( column.GetOffset() == 80 );
  assert( column.GetLength() == 8 );
  assert( column.GetType() == VALUE_TYPE_DOUBLE );

  constraints.clear();
  constraints = column.GetConstraints();
  assert( constraints.size() == 1 );
  type = constraints[0].GetType();
  assert( type == CONSTRAINT_TYPE_FOREIGN );
  name = constraints[0].GetName();
  assert( strcmp( name.c_str(), "THIS_IS_FOREIGN_CONSTRAINT") == 0 );

  printf("%s has been finished successfully\n", __func__ );
=======
  column = schema->GetColumnInfo(3);
  constraint_infos = column.GetConstraints();
  assert( constraint_infos.size() == 1 );
>>>>>>> bridge

  // TODO::CHECK::  reference table
  assert( constraint_infos[0].GetType() == CONSTRAINT_TYPE_FOREIGN );
  assert( strcmp( constraint_infos[0].GetName().c_str(), "THIS_IS_FOREIGN_CONSTRAINT") == 0 );
  assert( constraint_infos[0].GetReferenceTableOffset() == 1 );

  // TODO::CHECK:: pktable name and oid
  storage::DataTable* pktable = table->GetReferenceTable(0);
  assert( strcmp( (pktable->GetName()).c_str(), "pktable" ) == 0 );
  assert( table->GetId() == table_oid );

  // TODO::CHECK:: pktable size name, update/delete action
  pk_column_names.clear();
  fk_column_names.clear();
  pk_column_names  = table->GetReferenceTableInfo(0)->GetPKColumnNames();
  fk_column_names  = table->GetReferenceTableInfo(0)->GetFKColumnNames();
  assert( pk_column_names.size() == 1 );
  assert( fk_column_names.size() == 1 );
  assert(  strcmp( pk_column_names[0].c_str(), "name") == 0);
  assert(  strcmp( fk_column_names[0].c_str(), "salary") == 0);

  assert(  table->GetReferenceTableInfo(0)->GetUpdateAction() == 'r' );
  assert(  table->GetReferenceTableInfo(0)->GetDeleteAction() == 'c' );

  printf( COLOR_GREEN ":::::: %s DONE" COLOR_RESET "\n", __func__ );
}

void BridgeTest::RunTests() {
  printf( COLOR_BLUE "::::::::::::::::::::::::::::::::::::::::  TEST CASES START ::::::::::::::::::::::::::::::::::::::::" COLOR_RESET "\n" );
  DDL_CreateTable_TEST();
  printf( COLOR_BLUE "::::::::::::::::::::::::::::::::::::::::  TEST CASES END ::::::::::::::::::::::::::::::::::::::::::::" COLOR_RESET "\n");
}

void BridgeTest::TestCatalog() {
  GetDatabaseList();
}

} // End test namespace
} // End peloton namespace

