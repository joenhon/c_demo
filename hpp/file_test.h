//
// Created by xuniji on 2023/6/29.
//

#ifndef UNTITLED3_FILE_TEST_H
#define UNTITLED3_FILE_TEST_H

#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <codecvt>
#include <cstring>
#include "locality_pointer.h"
#include "grammar_test.h"

#endif //UNTITLED3_FILE_TEST_H
using namespace std;
using namespace pointer;
using namespace grammar;

enum encode {
    ANSI = 0,
    UTF_8 = 1,
    Unicode = 2,
} enCode;


namespace file {
    void readFile(const char *path, string &result) {
        static ifstream fin;
        fin.open(path, ios::in);
        stringstream str;
        if (fin.is_open()) {
//            char buf[1024];
//            while(fin.getline(buf,sizeof(buf))){
//                str.append(buf);
//                str.append("\n");
////                printf("%s",buf);
//            }
            char buf = 0;
            while (fin.get(buf) && !fin.eof()) {
//                str.append(voidToString(buf));
                str << buf;
//                printf("%c", buf);
            }
            //输出文字到下一个空格或换行符结束 lymy
//            string str1 ,str2;
//            fin >> str1 >>str2;
//            printf("str1:%s,str2:%s\n",str1.c_str(),str2.c_str());
        }
        fin.close();
        result.append(str.str());
    }

    void write(const char *path, const char *content) {
        ofstream f_out(path, ios::out | ios::binary | ios::app);
        if (f_out) {
//            f_out.write(content, strlen(content));
            //移动光标
            f_out.seekp(0, ios::end);
            f_out << content;
        }
        f_out.flush();
        f_out.close();
    }

    int GetFileEncoding(fstream *fs) {
        unsigned char ch = 0x00;
        fs->read((char *) &ch, sizeof(ch));//读取第一个字节，然后左移8位
        unsigned int coding = ch << 8;
        fs->read((char *) &ch, sizeof(ch));//读取第二个字节
        coding += ch;
        cout << coding << endl;

        encode code;
        switch (coding) {
            case 0xFFFE:
                // Unicode
                code = encode::Unicode;
                break;

            case 0xE6A2:
            case 0xE7BA:
                // UTF-8
                code = encode::UTF_8;
                break;
            default:
                // ANSI
                code = encode::ANSI;
                break;
        }
//        fs->close();
        return code;
    }

}
