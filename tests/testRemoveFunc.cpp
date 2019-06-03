# include  "catch.hpp"
# include  "hashtable.h"

TEST_CASE ("Testing of expected remove() functions","[hash-table]") {
    HashTable ht;
    ht.add(Identifier("some_element")); //hash()==226
    ht.add(Identifier("soccer"));   //hash()==226
    ht.add(Identifier("ABCDEFG"));  //hash()==131
    ht.add(Identifier("BA"));       //hash()==131
    
    
    SECTION("Remove existing element by id") {
        CHECK(removeElement(226));
        CHECK_FALSE(ht.get("some_element"));
        CHECK_FALSE(ht.get("soccer"));
    }
    SECTION("Remove existing element by name") {
        CHECK(removeElement("ABCDEFG"));
        CHECK_FALSE(ht.get("ABCDEFG"));
        CHECK(ht.get("BA"));
    }
    
    SECTION("Remove invalid elements by name") {
        CHECK_FALSE(removeElement(""));
        CHECK_FALSE(removeElement("\t"));
    }
    SECTION("Remove invalid elements by id") {
        CHECK_FALSE(removeElement(0));
        CHECK_FALSE(removeElement(63));
        CHECK_FALSE(removeElement(-100000));
    }
    
    
}
