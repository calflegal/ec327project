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
			    		//RelativeLayout fl = (RelativeLayout) v;
			    		//update the grid's index
			    		MainActivity.this.grid.selectAtTouch(x, y);
			    		MainActivity.this.drawCircleAtIndex(grid.selX,grid.selY);
			    		//MainActivity.this.grid.drawCircleAtCurrentSelected();
			    		//fl.addView(new Circle(fl.getContext(), thegrid.selX,thegrid.selY,25,count%2));
			    		//count++;
			    		return true;
			    	}
			    	else return false;
			    }
			});	
	}
	public void drawCircleAtIndex(int x,int y) {
		RelativeLayout gl = (RelativeLayout) findViewById(R.id.board_view);
		gl.addView(new Circle(gl.getContext(),
				(grid.width/2)+grid.selX*(grid.width),(grid.height/2)+grid.selY*(grid.height),25,count%2));
		count++;
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}


	

}
