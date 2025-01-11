package Java;

import java.util.Scanner;

public class Palindrom {
	
	public static String reverse(String text) {
		String result = "";
		int length = text.length();
		for(int i=length-1;i>=0;i--) {
			result+=text.charAt(i);
		}
		return result;
	}
	
	public static boolean isPalindrom(String text) {
		String re_text = reverse(text);
		
		if(text.equals(re_text)) {
			return true;
		}else {
			return false;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new  Scanner(System.in);
		while(true) {
			System.out.print("Enter a text here: ");
			String text = sc.next();
			
			if(text.equals("exit")) {
				break;
			}
			if(isPalindrom(text)) {
				System.out.println(text+" is a palindrom");
			}else {
				System.out.println(text+" is not a palindrom");
			}
		}

	}

}
