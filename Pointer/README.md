# Pointer
## ความหมาย
Pointer ในภาษาโปรแกรมมิ่งหมายถึงตัวแปรที่ใช้เก็บที่อยู่ของตัวแปรอื่นในหน่วยความจำ (memory address) แทนที่จะเก็บค่าของตัวแปรนั้นโดยตรง
## ประโยชน์
การใช้ pointer มีประโยชน์หลายอย่างในโปรแกรมมิ่ง โดยเฉพาะในภาษาเช่น C หรือ C++ ซึ่ง pointer ช่วยให้สามารถทำสิ่งต่อไปนี้:<br>
1. เข้าถึงและจัดการหน่วยความจำโดยตรง (Direct Memory Access)<br>
    - Pointer ช่วยให้เราสามารถเข้าถึงที่อยู่ของตัวแปรในหน่วยความจำได้โดยตรง ทำให้สามารถจัดการข้อมูลได้อย่างมีประสิทธิภาพ เช่น การสร้างตัวแปรแบบไดนามิก (dynamic memory allocation) ที่ใช้ malloc หรือ free เพื่อจัดการหน่วยความจำในระหว่างการทำงานของโปรแกรม<br>
2. การส่งตัวแปรเป็นอ้างอิง (Pass-by-Reference)<br>
    - ในบางกรณีเมื่อเราต้องการให้ฟังก์ชันสามารถแก้ไขค่าของตัวแปรที่ถูกส่งไป โดยไม่ต้องใช้การคัดลอกข้อมูลทั้งหมด (pass-by-value) เราสามารถใช้ pointer เพื่อส่งตัวแปรเป็นอ้างอิง (reference) แทนที่จะเป็นค่า ซึ่งช่วยให้การทำงานมีประสิทธิภาพมากขึ้น<br>
3. จัดการกับโครงสร้างข้อมูลที่ซับซ้อน (Dynamic Data Structures)<br>
    - Pointer ใช้ในการสร้างโครงสร้างข้อมูลที่มีความยืดหยุ่น เช่น linked list, binary tree, และ graph ซึ่งจำเป็นต้องใช้ pointer เพื่อเก็บที่อยู่ของข้อมูลต่างๆ ในหน่วยความจำ<br>
4. การทำงานกับอาร์เรย์ (Arrays)<br>
    - ในภาษา C, pointer และอาร์เรย์มีความสัมพันธ์กัน เพราะชื่อของอาร์เรย์จะถูกแปลงเป็นที่อยู่ของตัวแปรตัวแรกในอาร์เรย์ ซึ่งทำให้การทำงานกับอาร์เรย์สามารถใช้ pointer ได้<br>
5. เพิ่มประสิทธิภาพในการจัดการหน่วยความจำ<br>
    - การใช้ pointer สามารถช่วยลดการคัดลอกข้อมูลขนาดใหญ่ (เช่น อาร์เรย์หรือโครงสร้างข้อมูล) ซึ่งทำให้โปรแกรมทำงานได้เร็วขึ้นและใช้หน่วยความจำน้อยลง<br>
# Double pointer
## ความหมาย
Double pointer คือ pointer ที่เก็บที่อยู่ของ pointer ตัวอื่น ซึ่งหมายความว่าเป็น pointer ที่ชี้ไปยัง pointer อื่นๆ แทนที่จะชี้ไปยังตัวแปรธรรมดา โดยทั่วไปแล้ว double pointer จะใช้เมื่อเราต้องการจัดการกับข้อมูลที่ซับซ้อนมากขึ้นหรือเมื่อต้องการเปลี่ยนแปลงที่อยู่ของ pointer ภายในฟังก์ชัน (เช่น ในการจัดการหน่วยความจำแบบไดนามิกหรือโครงสร้างข้อมูลแบบลิงก์)<br>