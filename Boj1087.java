package boj1087;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

class Mouse{
	double t_x = 0, t_y = 0;
	double x, y, xx, yy;
	
	void location(double t){
		this.t_x = x + xx*t;
		this.t_y = y + yy*t;
	}
	void printLocation(){
		System.out.printf("x: %.10f, y: %.10f\n", this.t_x, this.t_y);
	}
	void initLocation(){
		this.t_x = x;
		this.t_y = y;
	}
}

public class Boj1087 {
	static double maxx, minx, maxy, miny;
	
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		double answer = 0;
		ArrayList<Mouse> mouses = new ArrayList<Mouse>(); 
		for(int i = 0; i < N; i++){
			Mouse tmp = new Mouse();
			tmp.x = s.nextInt();
			tmp.y = s.nextInt();
			tmp.xx = s.nextInt();
			tmp.yy = s.nextInt();
			mouses.add(tmp);
		}
		double l = 0, r = 4000, q1, q3, a1, a2;
		for(int i = 0; i < 100; i++){
			q1 = (l*2 + r)/3;
			q3 = (l+ r*2)/3;
			a1 = cal(q1,mouses);
			a2 = cal(q3,mouses);
			//System.out.printf("%.10f\n", a1);
			//System.out.printf("%.10f\n", a2);
			if(a1 > a2){
				l = q1;
				answer = a2;
			}else{
				r = q3;
				answer = a1;
			}
		}
		System.out.printf("%.10f", answer);
		
	}
	
	static double cal(double t, ArrayList<Mouse> mouses){
		maxx = -999999999;
		minx = 999999999; 
		maxy = -999999999; 
		miny = 999999999;
		
		Iterator it = mouses.iterator();
		while(it.hasNext()){
			Mouse mouse = (Mouse) it.next();
			mouse.location(t);
			//mouse.printLocation();
			if(maxx < mouse.t_x){
				maxx = mouse.t_x;
			}
			if(maxy < mouse.t_y){
				maxy = mouse.t_y;
			}
			if(minx > mouse.t_x){
				minx = mouse.t_x;
			}
			if(miny > mouse.t_y){
				miny = mouse.t_y;
			}
			
		}
		//System.out.printf("maxx : %.10f, minx : %.10f, maxy : %.10f, miny : %.10f\n", maxx, minx, maxy, miny);
		if(maxx-minx > maxy-miny){
			//System.out.println("maxx-minx"+(maxx-minx));
			return maxx-minx;
		}else{
			//System.out.println("maxy-miny"+(maxy-miny));
			return maxy-miny;
		}
		
	}
}
