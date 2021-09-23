#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

using namespace std;

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DateBaseConnect{
public:
    virtual bool login(string username, string password)
    {
        return true;
    }
    virtual bool logout(string username)
    {
        return true;
    }
    virtual int fetchRecord()
    {
        return -1;
    }
};

class MyDataBase{
    DateBaseConnect dbC;
public:
    MyDataBase(DateBaseConnect &_dbC): dbC(_dbC){}
    int Init(string username, string password)
    {
        if(dbC.login(username,password)!=true)
        {
            cout << "DB FAILURE"<<endl;
            return -1;
        }
        else
        {
            cout << "DB SUCCESS"<<endl;
            return 1;
        }
    }
};

class MockDB : public DateBaseConnect{
public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool(string username));
    MOCK_METHOD2(login,bool(string username, string password));
};

TEST(MyDBTest, LoginTest)
{
    MockDB mdb;
    MyDataBase db(mdb);
    EXPECT_CALL(mdb,login("hung","dang")).Times(1).WillOnce(Return(true));

    int returnValue = db.Init("hund", "dang");

    //EXPECT_EQ(returnValue,1);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}