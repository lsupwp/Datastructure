#include <stdio.h>
// ใช้สำหรับเรียกใช้ฟังก์ชัน printf() เพื่อแสดงผลบนหน้าจอ

int main() {
    int x = 10; 
    // ประกาศตัวแปรชนิด int ชื่อ x และกำหนดค่าเริ่มต้นเป็น 10

    int *ptr1 = &x; 
    // ประกาศตัวชี้ (pointer) ptr1 ซึ่งเก็บที่อยู่ของตัวแปร x

    int **ptr2 = &ptr1; 
    // ประกาศ double pointer (ตัวชี้ที่ชี้ไปยัง pointer) ptr2 ซึ่งเก็บที่อยู่ของ ptr1

    int ***ptr3 = &ptr2; 
    // ประกาศ triple pointer (ตัวชี้ที่ชี้ไปยัง double pointer) ptr3 ซึ่งเก็บที่อยู่ของ ptr2

    // แสดงที่อยู่ของตัวแปร x
    printf("Address of x:       %p\n", &x);

    // แสดงที่อยู่ของ ptr1
    printf("Address of ptr1:    %p\n", &ptr1);

    // แสดงที่อยู่ของ ptr2
    printf("Address of ptr2:    %p\n", &ptr2);

    // แสดงที่อยู่ของ ptr3
    printf("Address of ptr3:    %p\n", &ptr3);

    // แสดงค่าของ ptr1 (ที่อยู่ของ x)
    printf("Value of ptr1 = %p\n", ptr1);

    // แสดงค่าของ ptr2 (ที่อยู่ของ ptr1)
    printf("Value of ptr2 = %p\n", ptr2);

    // แสดงค่าของ ptr3 (ที่อยู่ของ ptr2)
    printf("Value of ptr3 = %p\n", ptr3);

    // แสดงค่าจริงของ x
    printf("Value of x =     %i\n", x);

    // ใช้ pointer ptr1 เพื่อแสดงค่าที่อยู่ในตัวแปร x
    printf("ptr1 true value: %i\n", *ptr1);

    // ใช้ double pointer ptr2 เพื่อแสดงค่าที่อยู่ในตัวแปร x
    printf("ptr2 true value: %i\n", **ptr2);

    // ใช้ triple pointer ptr3 เพื่อแสดงค่าที่อยู่ในตัวแปร x
    printf("ptr3 true value: %i\n", ***ptr3);

    return 0;
    // คืนค่า 0 เพื่อบอกว่าการทำงานของโปรแกรมเสร็จสมบูรณ์
}
