#include <unity.h>

#include <map.h>

static Map *map;


void setUp(void)
{
	map = Map_Create();
}


void tearDown(void)
{
	Map_Destroy(map);
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

