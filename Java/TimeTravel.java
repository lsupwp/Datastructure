package Java;

import java.util.Scanner;

public class TimeTravel {

	public static double cal(double distance, double speed) {
		double time = distance / speed;
		int hr = (int)time;
		double mn = ((time - hr) * 60) / 100;
		time = hr + mn;
		return time;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a distance(km): ");
		double distance = sc.nextDouble();
		while(true) {
			if(distance <= 0) {
				System.out.print("Invalid data, plese enter a new distance: ");
				distance = sc.nextDouble();
			}else{
				break;
			}
		}
		System.out.print("Enter a speed(km/h): ");
		double speed = sc.nextDouble();
		while(true) {
			if(speed <= 0) {
				System.out.print("Invalid data, plese enter a new speed: ");
				speed = sc.nextDouble();
			}else {
				break;
			}
		}
		double time = cal(distance, speed);
		
		int hr = (int)time;
		int mn = (int)((time - hr) * 100);
		
		
		if(time < 0.01) {
			System.out.println("Time used blow 1 minutes");
		}else {
			System.out.printf("Time used: %d hr %d", hr, mn);
		}
	}

}