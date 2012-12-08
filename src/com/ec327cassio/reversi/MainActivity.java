package com.ec327cassio.reversi;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.widget.RelativeLayout;
import android.widget.Toast;



public class MainActivity extends Activity {
	public Grid grid;
	public int[][] gamestate_int = new int[8][8];
	public Circle[][] gamestate_circles = new Circle[8][8];
	
	private int count = 0;
	static {
        System.loadLibrary("reversi");
    }
	public native String getString();
	//hi from nicole
	public void showToast(View v) {
		Toast.makeText(MainActivity.this, getString(), Toast.LENGTH_LONG).show();
		
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		 RelativeLayout main = (RelativeLayout) findViewById(R.id.board_view);
		 this.grid = new Grid(main.getContext());
		 main.addView(this.grid);
		 
		
		   this.grid.setOnTouchListener(new View.OnTouchListener() {
			    public boolean onTouch(View v, MotionEvent e) {
			    	if (e.getAction() == MotionEvent.ACTION_DOWN)  {
			    		int x = (int) e.getX();
			    		int y = (int) e.getY();
			    		//update the grid property for the space touched.
			    		MainActivity.this.grid.selectAtTouch(x, y);
			    		if (gameisnotover()) {MainActivity.this.tryMoveAtIndex(grid.selX,grid.selY);}
			    		return true;
			    	}
			    	else return false;
			    }
			});	
	}
	
	public boolean gameisnotover() {
		if (count < 64) {
			return true;
		}
		else return false;
		//call the end screen!
		
	}
	public void tryMoveAtIndex(int x,int y) {
		//get board view
		RelativeLayout gl = (RelativeLayout) findViewById(R.id.board_view);
		//if move allowed, add this one to the array. (this line should call c, passing
		// the index of the desired move.
			//if it's an okay move, add to array of circles.
			gamestate_circles[x][y] = new Circle(gl.getContext(),
					(grid.width/2)+grid.selX*(grid.width),(grid.height/2)+grid.selY*(grid.height),25,count%2);
		//	pass un-updated array to C, then change colors as needed (for loop)
		gl.addView(gamestate_circles[x][y]);
		count++;
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}


	

}
