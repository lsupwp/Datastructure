#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// กำหนดโครงสร้างข้อมูล Queue
typedef struct Queue {
    int size;        // จำนวนสมาชิกปัจจุบันในคิว (จำนวนข้อมูลในคิว)
    unsigned capacity; // ความจุสูงสุดของคิว (จำนวนข้อมูลที่คิวสามารถรองรับได้)
    int* array;      // ตัวชี้ไปยังอาร์เรย์ที่ใช้เก็บข้อมูลในคิว
} Queue;

Queue* createQueue(unsigned capacity) {
    // ฟังก์ชันนี้ใช้สำหรับสร้างคิวใหม่ที่สามารถเก็บข้อมูลได้สูงสุดตามความจุที่กำหนด
    // Parameter:
    //   - unsigned capacity: ความจุสูงสุดของคิว
    // Return:
    //   - Queue*: ตัวชี้ไปยังคิวที่ถูกสร้างขึ้นใหม่

    // จัดสรรหน่วยความจำสำหรับโครงสร้าง Queue
    Queue* queue = (Queue *)malloc(sizeof(Queue));

    // ตรวจสอบว่าการจัดสรรหน่วยความจำสำเร็จหรือไม่
    if (!queue) {
        printf("Error: Allocation failed!\n"); // แสดงข้อผิดพลาดหากไม่สามารถจัดสรรหน่วยความจำได้
        exit(1); // ออกจากโปรแกรม
    }

    // ตั้งค่าคุณสมบัติของคิว
    queue->capacity = capacity; // ตั้งค่าความจุสูงสุดของคิว
    queue->size = -1;            // ตั้งค่าขนาดเริ่มต้นของคิวเป็น -1 (คิวว่าง)
    
    // จัดสรรหน่วยความจำสำหรับอาร์เรย์ที่ใช้เก็บข้อมูลในคิว
    queue->array = (int *)malloc(capacity * sizeof(int));

    // ตรวจสอบการจัดสรรหน่วยความจำของอาร์เรย์
    if (!queue->array) {
        printf("Error: Allocation failed!\n"); // แสดงข้อผิดพลาดหากไม่สามารถจัดสรรอาร์เรย์ได้
        exit(1); // ออกจากโปรแกรม
    }

    // คืนค่าตัวชี้ไปยังคิวที่สร้างขึ้น
    return queue;
}

// ฟังก์ชันสำหรับปล่อยหน่วยความจำที่ใช้ในคิว
void freeQueue(Queue* queue) {
    // ตรวจสอบว่า queue เป็น NULL หรือไม่ก่อนที่จะดำเนินการ
    if (queue == NULL) {
        return; // หาก queue เป็น NULL ไม่ต้องทำอะไร
    }

    // ปล่อยหน่วยความจำของอาร์เรย์ที่เก็บข้อมูลในคิว
    free(queue->array); // ปล่อยหน่วยความจำที่จัดสรรไว้สำหรับอาร์เรย์ข้อมูลของคิว

    // ปล่อยหน่วยความจำที่จัดสรรให้กับตัวโครงสร้าง Queue
    free(queue); // ปล่อยหน่วยความจำที่จัดสรรไว้สำหรับตัวคิว
}

// ฟังก์ชันเช็คว่า queue เป็น NULL หรือไม่
int isNull(Queue* queue) {
    // คืนค่า 1 ถ้า queue เป็น NULL, คืนค่า 0 ถ้า queue ไม่เป็น NULL
    return queue == NULL;
}

// ฟังก์ชันเช็คว่า queue เต็มหรือไม่
int isFull(Queue* queue) {
    // ตรวจสอบว่า queue เป็น NULL หรือไม่
    if (isNull(queue)) {
        printf("Error: Queue is null!\n"); // แสดงข้อความข้อผิดพลาดถ้า queue เป็น NULL
        return INT_MIN; // คืนค่าที่ไม่ถูกต้องเพื่อแสดงข้อผิดพลาด
    }

    // คืนค่า 1 ถ้าคิวเต็ม, คืนค่า 0 ถ้าไม่เต็ม
    return queue->size == queue->capacity - 1;
}

// ฟังก์ชันเช็คว่า queue ว่างหรือไม่
int isEmpty(Queue* queue) {
    // ตรวจสอบว่า queue เป็น NULL หรือไม่
    if (isNull(queue)) {
        printf("Error: Queue is null!\n"); // แสดงข้อความข้อผิดพลาดถ้า queue เป็น NULL
        return INT_MIN; // คืนค่าที่ไม่ถูกต้องเพื่อแสดงข้อผิดพลาด
    }

    // คืนค่า 1 ถ้าคิวว่าง, คืนค่า 0 ถ้าคิวไม่ว่าง
    return queue->size == -1;
}

// ฟังก์ชันที่คืนขนาดของคิว
int sizeQueue(Queue* queue) {
    // ตรวจสอบว่า queue เป็น NULL หรือไม่
    if (isNull(queue)) {
        printf("Error: Queue is null!\n"); // แสดงข้อความข้อผิดพลาดถ้า queue เป็น NULL
        return INT_MIN; // คืนค่าที่ไม่ถูกต้องเพื่อแสดงข้อผิดพลาด
    }

    // คืนค่าขนาดของคิว (size + 1 เนื่องจาก size นับจาก 0)
    return queue->size + 1;
}

int enqueue(Queue* queue){

}

void main(){

}