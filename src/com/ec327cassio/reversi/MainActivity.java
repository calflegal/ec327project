package com.ec327cassio.reversi;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.FrameLayout;
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
		 FrameLayout main = (FrameLayout) findViewById(R.id.main_view);
		   main.addView(new Circle(this,50,50,25));
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

}
