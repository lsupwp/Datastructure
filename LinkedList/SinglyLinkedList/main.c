#include <stdio.h>
#include <stdlib.h>

// ประกาศโครงสร้าง (structure) ชื่อ Node
typedef struct Node {
    int data;               // ตัวแปร data เก็บข้อมูลชนิด int
    struct Node* next;      // ตัวชี้ (pointer) ชื่อ next ชี้ไปยัง Node ตัวถัดไป
} Node;

// ฟังก์ชัน createNode ใช้สำหรับสร้างโหนดใหม่
// รับพารามิเตอร์:
// - int data: ข้อมูลที่จะเก็บในโหนด
Node* createNode(int data) {
    // จองหน่วยความจำในฮีปสำหรับโหนดใหม่
    Node* newNode = (Node *)malloc(sizeof(Node));

    // ตรวจสอบว่าการจองหน่วยความจำสำเร็จหรือไม่
    if (!newNode) { // หาก newNode เป็น NULL
        printf("Error: Allowcation memory fieled!\n"); // แสดงข้อความข้อผิดพลาด
        exit(1); // ออกจากโปรแกรมโดยส่งสถานะ 1 (แสดงว่ามีข้อผิดพลาด)
    }

    // ตั้งค่าข้อมูลให้โหนดใหม่
    newNode->data = data; // กำหนดค่าของ data เป็นค่าที่รับมาผ่านพารามิเตอร์
    newNode->next = NULL; // ตั้งค่าตัวชี้ next เป็น NULL เพราะยังไม่มีโหนดถัดไป

    // คืนค่าตัวชี้ (pointer) ไปยังโหนดที่สร้างขึ้น
    return newNode;
}

// ฟังก์ชัน freeList ใช้สำหรับคืนหน่วยความจำที่ใช้ในลิงก์ลิสต์
// รับพารามิเตอร์:
// - Node* node: ตัวชี้ไปยังโหนดแรกของลิงก์ลิสต์
void freeList(Node* node) {
    Node* temp; // ตัวแปรชั่วคราวเพื่อเก็บที่อยู่ของโหนดถัดไป

    // วนลูปไปจนกว่า node จะเป็น NULL (ลิงก์ลิสต์จบลง)
    while (node) {
        temp = node->next;  // เก็บที่อยู่ของโหนดถัดไปไว้ใน temp
        free(node);         // คืนหน่วยความจำของโหนดปัจจุบัน
        node = temp;        // ตั้งค่า node ให้ชี้ไปยังโหนดถัดไป (ที่อยู่ใน temp)
    }
}

// ฟังก์ชัน showList ใช้สำหรับแสดงค่าของลิงก์ลิสต์
// รับพารามิเตอร์:
// - Node* node: ตัวชี้ไปยังโหนดแรกของลิงก์ลิสต์
void showList(Node* node) {
    printf("["); // เริ่มต้นแสดงลิงก์ลิสต์ในวงเล็บเหลี่ยม

    Node* temp = node; // ตัวแปร temp ชี้ไปยังโหนดแรกของลิงก์ลิสต์

    // วนลูปจนกว่าจะถึงโหนดสุดท้าย (จนกว่า temp จะเป็น NULL)
    while (temp) {
        // ตรวจสอบว่าโหนดปัจจุบันเป็นโหนดสุดท้ายหรือไม่
        if (temp->next == NULL) {
            printf("%i", temp->data); // ถ้าเป็นโหนดสุดท้ายแสดงข้อมูลโดยไม่มีจุลภาคตามหลัง
        } else {
            printf("%i, ", temp->data); // ถ้าไม่ใช่โหนดสุดท้ายแสดงข้อมูลและตามด้วยจุลภาค
        }

        temp = temp->next; // เปลี่ยน temp ไปยังโหนดถัดไป
    }

    printf("]\n"); // ปิดการแสดงผลในวงเล็บเหลี่ยม
}

// ฟังก์ชัน sizeNode ใช้สำหรับหาขนาดของลิงก์ลิสต์ (จำนวนโหนดในลิงก์ลิสต์)
// รับพารามิเตอร์:
// - Node* node: ตัวชี้ไปยังโหนดแรกของลิงก์ลิสต์
int sizeNode(Node* node) {
    int count = 0; // ตัวแปรสำหรับนับจำนวนโหนด
    Node* temp = node; // ใช้ temp เป็นตัวแปรในการเดินทางผ่านลิงก์ลิสต์

    // วนลูปจนกว่าจะถึงโหนดสุดท้าย (temp เป็น NULL)
    while (temp) {
        count++; // เพิ่มค่าจำนวนโหนด
        temp = temp->next; // เดินไปยังโหนดถัดไป
    }

    return count; // คืนค่าจำนวนโหนดทั้งหมด
}


// ฟังก์ชัน addToHead ใช้สำหรับเพิ่มโหนดใหม่ที่หัวลิงก์ลิสต์
// รับพารามิเตอร์:
// - Node** head: ตัวชี้ไปยังตัวชี้ของโหนดแรกในลิงก์ลิสต์ (ใช้ **เพื่อให้สามารถเปลี่ยนแปลงค่าหัวลิสต์ได้)
// - int data: ข้อมูลที่จะเพิ่มในโหนดใหม่
int addToHead(Node** head, int data) {
    // ตรวจสอบว่า head เป็น NULL หรือไม่
    if (!head) {
        // ถ้า head เป็น NULL (ไม่มีลิงก์ลิสต์), สร้างโหนดใหม่และตั้งเป็นหัวลิงก์
        *head = createNode(data);
        return 0; // การเพิ่มเสร็จสิ้น
    }

    // ถ้า head ไม่เป็น NULL (มีลิงก์ลิสต์), สร้างโหนดใหม่
    Node* newNode = createNode(data);

    // ตั้งค่า newNode->next ให้ชี้ไปยังโหนดแรกที่เป็นหัวลิงก์เดิม
    newNode->next = *head;

    // ตั้งค่า *head ให้ชี้ไปยัง newNode ซึ่งเป็นโหนดใหม่ที่เพิ่มไปที่หัว
    *head = newNode;

    return 0; // การเพิ่มเสร็จสิ้น
}

// ฟังก์ชัน addToTail ใช้สำหรับเพิ่มโหนดใหม่ที่ท้ายลิงก์ลิสต์
// รับพารามิเตอร์:
// - Node** head: ตัวชี้ไปยังตัวแปร head ของลิงก์ลิสต์
// - int data: ข้อมูลที่จะเพิ่มในโหนดใหม่
int addToTail(Node** head, int data) {
    // ถ้า head เป็น NULL (ลิงก์ลิสต์ว่าง)
    if (!head) {
        // สร้างโหนดใหม่ที่เก็บข้อมูล data และตั้งเป็นหัวลิสต์
        *head = createNode(data);
        return 0; // การเพิ่มโหนดสำเร็จ
    }

    // ถ้า head ไม่เป็น NULL (มีลิงก์ลิสต์แล้ว)
    Node* newNode = createNode(data); // สร้างโหนดใหม่ที่เก็บข้อมูล data

    // ใช้ temp เพื่อเดินผ่านลิงก์ลิสต์
    Node* temp = *head;

    // วนลูปจนถึงโหนดสุดท้าย
    while (temp) {
        // หาก temp->next เป็น NULL แสดงว่า temp เป็นโหนดสุดท้าย
        if (temp->next == NULL) {
            temp->next = newNode; // เชื่อมโยง newNode ไปที่ temp->next (ทำให้ newNode เป็นโหนดสุดท้าย)
            return 0; // การเพิ่มโหนดสำเร็จ
        }
        // ถ้ายังไม่ถึงโหนดสุดท้าย, เดินไปยังโหนดถัดไป
        temp = temp->next;
    }

    // ถ้ามาถึงจุดนี้ แสดงว่าเกิดข้อผิดพลาด (ไม่ควรเกิดขึ้นในกรณีนี้)
    printf("Error: Add node fieled!\n");
    return 1; // การเพิ่มโหนดล้มเหลว
}

// ฟังก์ชัน updateNode ใช้สำหรับอัพเดตข้อมูลในโหนดที่ตำแหน่งที่กำหนด
// รับพารามิเตอร์:
// - Node* node: ตัวชี้ไปยังโหนดแรกของลิงก์ลิสต์
// - int pos: ตำแหน่งที่ต้องการอัพเดตข้อมูล (เริ่มต้นที่ 1)
// - int data: ข้อมูลใหม่ที่ต้องการอัพเดตในโหนดที่ตำแหน่ง pos
int updateNode(Node* node, int pos, int data) {
    // ตรวจสอบว่า node ไม่เป็น NULL
    if (!node) {
        printf("Error: Node is null!\n"); // ถ้า node เป็น NULL, แสดงข้อความผิดพลาด
        return 1; // คืนค่าผิดพลาด
    }

    // ตรวจสอบว่า pos อยู่ในช่วงที่ถูกต้อง (ระหว่าง 1 ถึงขนาดของลิงก์ลิสต์)
    if (pos > sizeNode(node) || pos < 1) {
        printf("Error: Invalid position!\n"); // ถ้าตำแหน่งไม่ถูกต้อง, แสดงข้อความผิดพลาด
        return 1; // คืนค่าผิดพลาด
    }

    // ใช้ temp เป็นตัวแปรในการเดินทางไปยังตำแหน่ง pos
    Node* temp = node;

    // วนลูปไปยังตำแหน่งที่ต้องการอัพเดต (เริ่มที่ตำแหน่ง 1)
    for (int i = 1; i < pos; i++) {
        temp = temp->next; // เดินไปยังโหนดถัดไปจนถึงตำแหน่ง pos
    }

    // อัพเดตข้อมูลในโหนดที่ตำแหน่ง pos
    temp->data = data;

    return 0; // คืนค่า 0 เพื่อบ่งชี้ว่าการอัพเดตสำเร็จ
}

// ฟังก์ชัน getNext ใช้สำหรับดึงตัวชี้ไปยังโหนดถัดไปจากตำแหน่งที่ระบุ
// รับพารามิเตอร์:
// - Node* node: ตัวชี้ไปยังโหนดแรกของลิงก์ลิสต์
// - int pos: ตำแหน่งของโหนดที่ต้องการดึงตัวชี้ไปยังโหนดถัดไป (เริ่มต้นที่ 1)
Node* getNext(Node* node, int pos) {
    // ตรวจสอบว่า pos อยู่ในช่วงที่ถูกต้อง (ระหว่าง 1 ถึงขนาดของลิงก์ลิสต์)
    if (pos > sizeNode(node) || pos < 1) {
        printf("Error: Invalid position!\n"); // แสดงข้อความผิดพลาดถ้าตำแหน่งไม่ถูกต้อง
        return NULL; // คืนค่า NULL เพื่อบ่งบอกถึงข้อผิดพลาด
    }

    // ใช้ temp เป็นตัวแปรในการเดินทางไปยังตำแหน่ง pos
    Node* temp = node;

    // วนลูปไปยังตำแหน่งที่ระบุ (เริ่มจากตำแหน่ง 1)
    for (int i = 1; i < pos; i++) {
        temp = temp->next; // เดินไปยังโหนดถัดไป
    }

    // คืนค่าตัวชี้ไปยังโหนดถัดไปจากตำแหน่งที่ระบุ
    return temp->next;
}


// ฟังก์ชัน setNext ใช้สำหรับตั้งค่าตัวชี้ next ให้กับโหนดในลิงก์ลิสต์
// รับพารามิเตอร์:
// - Node* node: ตัวชี้ไปยังโหนดแรกของลิงก์ลิสต์
// - int pos: ตำแหน่งของโหนดที่ต้องการเปลี่ยนตัวชี้ next (เริ่มจากตำแหน่งที่ 1)
// - Node* next: ตัวชี้ไปยังโหนดใหม่ที่ต้องการตั้งเป็น next
// คืนค่า 0 หากสำเร็จ และ 1 หากเกิดข้อผิดพลาด
int setNext(Node* node, int pos, Node* next) {
    // ตรวจสอบว่า pos อยู่ในช่วงที่ถูกต้อง (ระหว่าง 1 ถึงขนาดของลิงก์ลิสต์)
    if (pos > sizeNode(node) || pos < 1) {
        printf("Error: Invalid position!\n"); // แสดงข้อความผิดพลาดหากตำแหน่งไม่ถูกต้อง
        return 1; // คืนค่า 1 เพื่อระบุข้อผิดพลาด
    }

    // ตรวจสอบว่า next ไม่ใช่ NULL
    if (next == NULL) {
        printf("Error: Next is null!\n"); // แสดงข้อความผิดพลาดหาก next เป็น NULL
        return 1; // คืนค่า 1 เพื่อระบุข้อผิดพลาด
    }

    // ใช้ temp เป็นตัวแปรในการเดินทางไปยังตำแหน่ง pos
    Node* temp = node;

    // วนลูปไปยังตำแหน่งที่ระบุ (เริ่มจากตำแหน่ง 1)
    for (int i = 1; i < pos; i++) {
        temp = temp->next; // เดินไปยังโหนดถัดไป
    }

    // ตั้งค่าตัวชี้ next ของโหนดที่ตำแหน่ง pos ให้ชี้ไปยัง next
    temp->next = next;

    // คืนค่า 0 เพื่อระบุว่าการตั้งค่าประสบความสำเร็จ
    return 0;
}


// ฟังก์ชัน insertNode ใช้สำหรับแทรกโหนดใหม่ในตำแหน่งที่ระบุในลิงก์ลิสต์
// รับพารามิเตอร์:
// - Node* node: ตัวชี้ไปยังโหนดแรกของลิงก์ลิสต์
// - int pos: ตำแหน่งที่ต้องการแทรกโหนดใหม่ (ตำแหน่งเริ่มจาก 1)
// - int data: ข้อมูลที่ต้องการบรรจุในโหนดใหม่
// คืนค่า 0 หากสำเร็จ และ 1 หากเกิดข้อผิดพลาด
int insertNode(Node* node, int pos, int data) {
    // ตรวจสอบว่า pos อยู่ในช่วงที่เหมาะสม (ระหว่าง 2 ถึงขนาดของลิงก์ลิสต์)
    if (pos >= sizeNode(node) || pos <= 1) {
        printf("Error: Invalid position!\n"); // แสดงข้อความผิดพลาดหากตำแหน่งไม่ถูกต้อง
        return 1; // คืนค่า 1 เพื่อระบุข้อผิดพลาด
    }

    // สร้างโหนดใหม่โดยใช้ข้อมูลที่ระบุ
    Node* newNode = createNode(data);

    // ดึงตัวชี้ไปยังโหนดถัดไปจากตำแหน่งก่อนหน้า
    Node* next = getNext(node, pos - 1);

    // ตั้งค่าตัวชี้ของโหนดที่ตำแหน่งก่อนหน้าให้ชี้ไปยังโหนดใหม่
    setNext(node, pos - 1, newNode);

    // ตั้งค่าตัวชี้ของโหนดใหม่ให้ชี้ไปยังโหนดถัดไป
    newNode->next = next;

    // คืนค่า 0 เพื่อแสดงว่าการแทรกสำเร็จ
    return 0;
}

// ฟังก์ชัน deleteNode ใช้สำหรับลบโหนดในตำแหน่งที่ระบุจากลิงก์ลิสต์
// รับพารามิเตอร์:
// - Node** head: ตัวชี้คู่ (double pointer) ไปยังหัวลิงก์ลิสต์
// - int pos: ตำแหน่งของโหนดที่ต้องการลบ (เริ่มจาก 1)
// คืนค่า 0 หากสำเร็จ และ 1 หากเกิดข้อผิดพลาด
int deleteNode(Node** head, int pos) {
    // ตรวจสอบว่าลิงก์ลิสต์ว่างหรือไม่
    if (!*head) {
        printf("Error: List is null!\n"); // แสดงข้อความผิดพลาด
        return 1; // คืนค่า 1 เพื่อระบุข้อผิดพลาด
    }

    // ตรวจสอบว่าตำแหน่งที่ระบุอยู่ในช่วงที่ถูกต้อง
    if (pos > sizeNode(*head) || pos < 1) {
        printf("Error: Invalid position!\n"); // แสดงข้อความผิดพลาด
        return 1; // คืนค่า 1 เพื่อระบุข้อผิดพลาด
    }

    // กรณีลบโหนดตำแหน่งแรก (head)
    if (pos == 1) {
        Node* temp = *head;     // เก็บตัวชี้ไปยังโหนดแรก
        *head = temp->next;     // เปลี่ยนตัวชี้หัวไปยังโหนดถัดไป
        free(temp);             // ลบโหนดแรก
        return 0;               // คืนค่า 0 เพื่อระบุความสำเร็จ
    }

    // กรณีลบโหนดตำแหน่งสุดท้าย
    if (pos == sizeNode(*head)) {
        Node* pre = *head;      // ใช้ตัวชี้ `pre` เดินไปยังโหนดก่อนหน้าโหนดสุดท้าย
        for (int i = 1; i < pos - 1; i++) {
            pre = pre->next;
        }
        Node* temp = pre->next; // เก็บตัวชี้ไปยังโหนดสุดท้าย
        pre->next = NULL;       // ตัดตัวชี้ `next` ของโหนดก่อนหน้าโหนดสุดท้าย
        free(temp);             // ลบโหนดสุดท้าย
        return 0;               // คืนค่า 0 เพื่อระบุความสำเร็จ
    }

    // กรณีลบโหนดตำแหน่งทั่วไป
    Node* next = getNext(*head, pos);         // ดึงตัวชี้ไปยังโหนดถัดไปของตำแหน่งที่ต้องการลบ
    Node* temp = getNext(*head, pos - 1);     // ดึงตัวชี้ไปยังโหนดปัจจุบันที่ต้องการลบ
    setNext(*head, pos - 1, next);            // ตั้งค่าตัวชี้ `next` ของโหนดก่อนหน้าให้ชี้ไปยังโหนดถัดไป

    free(temp);                               // ลบโหนดปัจจุบัน
    return 0;                                 // คืนค่า 0 เพื่อระบุความสำเร็จ
}


int main() {
    Node* head = NULL; // สร้างตัวชี้ `head` ซึ่งเริ่มต้นเป็น NULL (ลิงก์ลิสต์ว่าง)

    addToHead(&head, 10); // เพิ่มโหนดที่มีค่า 10 เป็นโหนดแรกของลิงก์ลิสต์

    addToTail(&head, 20); // เพิ่มโหนดที่มีค่า 20 ไปยังตำแหน่งสุดท้าย
    addToTail(&head, 30); // เพิ่มโหนดที่มีค่า 30 ไปยังตำแหน่งสุดท้าย
    addToTail(&head, 40); // เพิ่มโหนดที่มีค่า 40 ไปยังตำแหน่งสุดท้าย
    addToTail(&head, 50); // เพิ่มโหนดที่มีค่า 50 ไปยังตำแหน่งสุดท้าย

    showList(head); // แสดงลิงก์ลิสต์

    updateNode(head, 1, 99); // อัปเดตข้อมูลในโหนดตำแหน่งที่ 1 ให้เป็น 99
    showList(head);          // แสดงลิงก์ลิสต์

    insertNode(head, 2, 110); // แทรกโหนดใหม่ที่มีค่า 110 ที่ตำแหน่ง 2
    showList(head);           // แสดงลิงก์ลิสต์

    deleteNode(&head, 6); // ลบโหนดในตำแหน่งที่ 6
    showList(head);       // แสดงลิงก์ลิสต์

    freeList(head); // ลบลิงก์ลิสต์ทั้งหมดและคืนหน่วยความจำ
    return 0;       // คืนค่า 0 เพื่อบ่งบอกว่าฟังก์ชันทำงานสำเร็จ
}
