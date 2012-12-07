package com.ec327cassio.reversi;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.GridLayout;
import android.widget.Toast;



public class MainActivity extends Activity {
	
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
		 GridLayout main = (GridLayout) findViewById(R.id.grid_view);
		 
		
		   main.setOnTouchListener(new View.OnTouchListener() {
			    public boolean onTouch(View v, MotionEvent e) {
			    	if (e.getAction() == MotionEvent.ACTION_DOWN)  {
			    		float x = e.getX();
			    		float y = e.getY();
			    		GridLayout gridView = (GridLayout) v;
			    		gridView.addView(new Circle(gridView.getContext(), x,y,25,true));
			    		return true;
			    	}
			    	else return false;
			    }
			});	
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}


	

}
