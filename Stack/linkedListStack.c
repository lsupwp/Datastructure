#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    int top;
    Node* list;
} Stack;

Node* createNode(int data) {
    // จัดสรรหน่วยความจำสำหรับโหนดใหม่
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { // ตรวจสอบว่าการจัดสรรหน่วยความจำสำเร็จหรือไม่
        printf("Error: Memory allocation failed!\n");
        exit(1); // ออกจากโปรแกรมหากหน่วยความจำไม่เพียงพอ
    }

    // กำหนดค่าให้กับโหนดใหม่
    newNode->data = data;  // เก็บข้อมูลในฟิลด์ data
    newNode->next = NULL;  // ตั้งค่าให้ลิงก์ของโหนดใหม่เป็น NULL

    return newNode; // คืนค่าโหนดใหม่กลับไป
}

Stack* createStack() {
    // จัดสรรหน่วยความจำสำหรับโครงสร้าง Stack
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) { // ตรวจสอบว่าการจัดสรรหน่วยความจำสำเร็จหรือไม่
        printf("Error: Memory allocation failed!\n");
        exit(1); // ออกจากโปรแกรมหากการจัดสรรหน่วยความจำล้มเหลว
    }

    // กำหนดค่าเริ่มต้นให้กับโครงสร้าง Stack
    stack->top = -1;       // กำหนดตำแหน่งเริ่มต้นของสแตกเป็น -1 (แสดงว่าว่าง)
    stack->list = NULL;    // ตั้งค่า list ให้เป็น NULL (ยังไม่มีโหนดใดๆ)

    return stack; // คืนค่าตัวชี้ไปยัง Stack ที่สร้างขึ้น
}

void freeStack(Stack* stack) {
    // ตรวจสอบว่า stack เป็น NULL หรือไม่
    // Parameter:
    //   - Stack* stack: ตัวชี้ไปยังสแตกที่ต้องการปล่อยหน่วยความจำ
    // Return:
    //   - ไม่มีการคืนค่า เนื่องจากเป็นฟังก์ชันที่ทำงานเพื่อปล่อยหน่วยความจำ

    if (!stack) { // ถ้าสแตกเป็น NULL
        return; // ไม่ต้องทำอะไร ถ้าเป็น NULL
    }

    Node* temp;

    // ปล่อยหน่วยความจำของโหนดแต่ละตัวในลิงก์ลิสต์
    // ลูปนี้จะเดินผ่านโหนดทั้งหมดในลิงก์ลิสต์และปล่อยหน่วยความจำ
    while (stack->list) {
        temp = stack->list->next; // เก็บลิงก์ไปยังโหนดถัดไป
        free(stack->list);        // ปล่อยหน่วยความจำของโหนดปัจจุบัน
        stack->list = temp;       // ย้ายไปยังโหนดถัดไป
    }

    // ปล่อยหน่วยความจำของโครงสร้าง Stack
    free(stack); // ปล่อยหน่วยความจำที่จัดสรรให้กับโครงสร้าง Stack
}

int isEmpty(Stack* stack) {
    return stack->top == -1; // คืนค่า 1 (true) ถ้าสต็กว่าง, 0 (false) ถ้าไม่ว่าง
}

int isNull(Stack* stack) {
    return stack == NULL; // คืนค่า 1 (true) ถ้าสต็กเป็น NULL, 0 (false) ถ้าไม่ใช่
}

// ฟังก์ชันสำหรับเพิ่มข้อมูลลงในสแตก
// พารามิเตอร์:
// - Stack** stack: ตัวชี้ไปยังตัวชี้ของโครงสร้างสแตก
// - int data: ข้อมูลที่จะเพิ่มลงในสแตก
// คืนค่า:
// - 1: ถ้าเพิ่มข้อมูลสำเร็จ
// - 0: ถ้าเพิ่มข้อมูลไม่สำเร็จ
int push(Stack** stack, int data) {
    // ตรวจสอบว่าพอยน์เตอร์ stack เป็น NULL หรือไม่
    if (isNull((*stack))) {
        printf("Error: stack is null!\n");
        return 0; // เพิ่มข้อมูลไม่สำเร็จ
    }

    // สร้างโหนดใหม่เพื่อเก็บข้อมูล
    Node* newNode = createNode(data);

    // เก็บลิงก์ของโหนดปัจจุบันใน temp
    Node* temp = (*stack)->list;

    // อัปเดตค่าบนสุดของสแตก (top) และลิงก์ของโหนดใหม่
    (*stack)->top = (*stack)->top + 1;
    (*stack)->list = newNode;
    (*stack)->list->next = temp;

    return 1; // เพิ่มข้อมูลสำเร็จ
}

int peek(Stack* stack) {
    // ตรวจสอบว่าสแตก (stack) เป็น NULL หรือไม่
    // Parameter:
    //   - Stack* stack: ตัวชี้ไปยังโครงสร้างข้อมูลสแตกที่ต้องการดูค่าบนสุด
    // Return: 
    //   - หากสแตกเป็น NULL จะคืนค่า INT_MIN เพื่อแสดงข้อผิดพลาด
    if (isNull(stack)) { 
        printf("Error: Stack is null!\n"); // แจ้งข้อผิดพลาดว่าสแตกเป็น NULL
        return INT_MIN; // คืนค่าที่แสดงข้อผิดพลาด (INT_MIN)
    }

    // ตรวจสอบว่าสแตกว่างหรือไม่
    // สแตกว่างหมายถึงไม่มีข้อมูลในสแตก
    // Return:
    //   - หากสแตกว่าง จะคืนค่า INT_MIN เพื่อแสดงข้อผิดพลาด
    if (isEmpty(stack)) { 
        printf("Error: Stack is empty!\n"); // แจ้งข้อผิดพลาดว่าสแตกว่าง
        return INT_MIN; // คืนค่าที่แสดงข้อผิดพลาด (INT_MIN)
    }

    // คืนค่าข้อมูลของโหนดบนสุดในสแตก
    // stack->list ชี้ไปยังโหนดบนสุดในลิงก์ลิสต์ที่เป็นโครงสร้างของสแตก
    // stack->list->data คือค่าข้อมูลในโหนดบนสุด
    return stack->list->data; 
}

int pop(Stack** stack) {
    // ตรวจสอบว่าสแตก (stack) เป็น NULL หรือไม่
    // Parameter:
    //   - Stack** stack: ตัวชี้ไปยังสแตกที่ต้องการลบข้อมูลบนสุด
    // Return:
    //   - หากสแตกเป็น NULL จะคืนค่า 0 เพื่อแสดงข้อผิดพลาด
    if (isNull(*stack)) { 
        printf("Error: Stack is null!\n"); // แจ้งข้อผิดพลาดว่าสแตกเป็น NULL
        return 0; // คืนค่า 0 เพื่อแสดงข้อผิดพลาด
    }

    // ตรวจสอบว่าสแตกว่างหรือไม่
    // สแตกว่างหมายถึงไม่มีข้อมูลในสแตก
    // Return:
    //   - หากสแตกว่างจะคืนค่า 0 เพื่อแสดงข้อผิดพลาด
    if (isEmpty(*stack)) { 
        printf("Error: Stack is empty!\n"); // แจ้งข้อผิดพลาดว่าสแตกว่าง
        return 0; // คืนค่า 0 เพื่อแสดงข้อผิดพลาด
    }

    // เก็บโหนดบนสุดชั่วคราวไว้ในตัวแปร temp
    // (*stack)->list ชี้ไปยังโหนดบนสุดของสแตก
    Node* temp = (*stack)->list;

    // ย้าย pointer ไปยังโหนดถัดไป
    // หลังจากการลบโหนดบนสุด pointer list จะชี้ไปยังโหนดถัดไป
    (*stack)->list = temp->next;

    // ลดค่า top ของสแตก
    (*stack)->top--; 

    // ปล่อยหน่วยความจำของโหนดที่ลบ
    free(temp);

    return 1; // คืนค่าความสำเร็จ (1) หลังจากการลบโหนด
}


int sizeStack(Stack* stack) {
    // ตรวจสอบว่าสแตก (stack) เป็น NULL หรือไม่
    // Parameter:
    //   - Stack* stack: ตัวชี้ไปยังสแตกที่ต้องการหาขนาด
    // Return:
    //   - หากสแตกเป็น NULL จะคืนค่า INT_MIN เพื่อแสดงข้อผิดพลาด
    if (isNull(stack)) { 
        printf("Error: Stack is null!\n"); // แจ้งข้อผิดพลาดว่าสแตกเป็น NULL
        return INT_MIN; // คืนค่าที่แสดงข้อผิดพลาด (INT_MIN)
    }

    // คืนค่าขนาดของสแตก โดยขนาดคือ top + 1
    // ค่า top ของสแตกจะเก็บตำแหน่งของโหนดบนสุด (เริ่มจาก 0)
    // ดังนั้นขนาดของสแตกคือ top + 1
    return stack->top + 1; 
}


void main(){
    Stack* stack1 = createStack();
    Stack* stack2 = createStack();

    push(&stack1, 10);
    int result = peek(stack1);

    if(result!=INT_MIN){
        printf("Top stack1 is: %i\n", result);
    }

    push(&stack1, 20);
    result = peek(stack1);

    if(result!=INT_MIN){
        printf("Top stack1 is: %i\n", result);
    }

    push(&stack1, 30);
    result = peek(stack1);

    if(result!=INT_MIN){
        printf("Top stack1 is: %i\n", result);
    }

    printf("Size Stack1 is: %i\n", sizeStack(stack1));

    pop(&stack1);
    result = peek(stack1);

    if(result!=INT_MIN){
        printf("Top stack1 is: %i\n", result);
    }

    printf("Size Stack1 is: %i\n", sizeStack(stack1));
    printf("Size Stack2 is: %i\n", sizeStack(stack2));

    int empty = isEmpty(stack1);
    if(empty == 1){
        printf("Stack1 is empty!\n");
    }else{
        printf("Stack1 is not empty!\n");
    }

    empty = isEmpty(stack2);
    if(empty == 1){
        printf("Stack2 is empty!\n");
    }else{
        printf("Stack2 is not empty!\n");
    }

    freeStack(stack1);
    freeStack(stack2);
}