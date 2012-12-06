package com.ec327cassio.reversi;


import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	static {
        System.loadLibrary("reversi");
    }
	public native String getString();
	
	public void showToast(View v) {
		Toast.makeText(MainActivity.this, getString(), Toast.LENGTH_LONG).show();
		
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}
	
	public void gotoSettings(View view){
		Intent intent = new Intent(this, Game_Settings.class);
		startActivity(intent);
	}
	
	public void gotoHelp(View view){
		Intent intent = new Intent(this, Game_Help.class);
		startActivity(intent);
	}
	public void gotoStart(View view){
		Intent intent = new Intent(this, Game_Start.class);
		startActivity(intent);
	}
	
	
}
