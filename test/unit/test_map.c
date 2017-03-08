#include <unity.h>
#include <Mockkey.h>

#include <map.h>

static Map *map;


void setUp(void)
{
	Mockkey_Init();
	map = Map_Create();
}


void tearDown(void)
{
	Map_Destroy(map);
	Mockkey_Verify();
}


void should_create_and_destroy_map(void)
{
	TEST_ASSERT_NOT_NULL(map);
	TEST_ASSERT_TRUE(Map_isEmpty(map));
}


void should_not_be_empty_after_inserting_an_element(void)
{
	int value;
	int ret;
	Key *key = NULL;

	ret = Map_Insert(map, key, &value);

	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_FALSE(Map_isEmpty(map));
}


void should_not_be_allowed_to_insert_twice_the_same_key(void)
{
	int value;
	int ret;
	Key *key = NULL;

	Map_Insert(map, key, &value);

	ret = Map_Insert(map, key, &value);

	TEST_ASSERT_EQUAL_INT(-1, ret);
}


void should_find_an_inserted_value_by_key(void)
{
	int value;
	void *value_found;
	Key *key = NULL;

	Map_Insert(map, key, &value);

	value_found = Map_Find(map, key);

	TEST_ASSERT_EQUAL_PTR(&value, value_found);
}


void should_be_empty_after_deleting_the_only_value_by_key(void)
{
	int value;
	Key *key = NULL;

	Map_Insert(map, key, &value);

	Map_Delete(map, key);

	TEST_ASSERT_TRUE(Map_isEmpty(map));
}


void should_not_find_an_inserted_value_after_removing_it(void)
{
	int value;
	Key *key = NULL;

	Map_Insert(map, key, &value);

	Map_Delete(map, key);

	TEST_ASSERT_NULL(Map_Find(map, key));
}


void should_insert_many_keys_in_the_map(void)
{
	int value1, value2, ret;
	Key *key1 = NULL, *key2 = NULL;

	ret = Map_Insert(map, key1, &value1);
	TEST_ASSERT_EQUAL_INT(0, ret);

	ret = Map_Insert(map, key2, &value2);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

