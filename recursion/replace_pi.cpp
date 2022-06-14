// // replace pi with 3.14 in string


// FIND ERROR(NOT WORKING PROPERLY)
// #include<bits/stdc++.h>
// using namespace std;

// string replace_pi(string str){
//     if(str.length() == 0)
//         return "";

//     if(str.substr(0, 2) == "pi")
//         return "3.14" + str.substr(2);

//     return str[0] + replace_pi(str.substr(1));
// }

// int main()
// {
//     string str = "pippxxppiixipi";
//     // cout << str[0] << " " << str.substr(1);
//     cout << replace_pi(str);
//     return 0;
// }