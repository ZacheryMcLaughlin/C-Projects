#ifndef STRUCTS_H
#define STRUCTS_H

struct employee //*Struct that holds the employee information
{
    int id;
    string password;
    string first_name;
    string last_name;
};

struct hours //*Struct that holds the hours and days information.
{
    string day;
    string open_hour;
    string close_hour;
};

#endif