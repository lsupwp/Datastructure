#include <stdio.h> 
// ใช้สำหรับเรียกใช้ฟังก์ชัน printf() เพื่อแสดงผลลัพธ์บนหน้าจอ

int main() {
    char a = 'A'; 
    // ประกาศตัวแปรชนิด char ชื่อ a และกำหนดค่าเริ่มต้นเป็น 'A' (ตัวอักษร)

    char* ptr = &a; 
    // ประกาศตัวชี้ (pointer) ชื่อ ptr และเก็บค่าที่อยู่ของตัวแปร a

    // แสดงค่าของตัวแปร a
    printf("Value of a is %c\n", a); 
    // ใช้ฟอร์แมตสตริง %c เพื่อแสดงตัวอักษรในตัวแปร a

    // แสดงค่าของ ptr ซึ่งเป็นค่าที่อยู่ที่ตัวชี้นี้ชี้ไป
    printf("Value of ptr is     %p\n", ptr); 
    // ใช้ฟอร์แมตสตริง %p เพื่อแสดงค่าที่อยู่ในรูปแบบเลขฐาน 16

    // แสดงค่าที่อยู่ของตัวแปร a
    printf("Address of a is     %p\n", &a); 
    // ใช้ฟอร์แมตสตริง %p เช่นกัน ค่านี้ควรจะเท่ากับค่าของ ptr

    // แสดงค่าที่อยู่ของตัวแปร ptr เอง
    printf("Address of ptr is   %p\n", &ptr); 
    // ค่านี้จะแตกต่างจากค่าที่อยู่ของ a เนื่องจาก ptr เป็นตัวแปรคนละตัว

    // ใช้ตัวชี้ ptr เพื่อดึงค่าของตัวแปร a และแสดงค่า
    printf("Value in address:   %p is %c\n", ptr, *ptr); 
    // *ptr คือการดึงค่าที่เก็บอยู่ในที่อยู่ที่ ptr ชี้ไป (derefencing)

    return 0; 
    // คืนค่า 0 เพื่อบอกให้ระบบทราบว่าการทำงานของโปรแกรมเสร็จสิ้นสมบูรณ์
}
