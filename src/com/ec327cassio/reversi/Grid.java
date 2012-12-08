package com.ec327cassio.reversi;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.Log;
import android.view.View;

public class Grid extends View{
    public float width;    // width of one tile
    public float height;    // height on one tile
    public int selX;        // X index of selection
    public int selY;        // Y index of selection
    public final Rect selRect = new Rect();  // selected rectangle
    private final Paint mPaint;
	
public Grid(Context context) {
        super(context);
     //   this.width=width;
       // this.height=height;
        this.mPaint = new Paint();
        
} 



        
private void getRect(int x, int y, Rect rect) {
        rect.set((int)(x = (int) width), (int) (y = (int) height), 
                (int)(x * width + width), (int) (y * height + height));
    }
   
@Override
protected void onSizeChanged(int w, int h, int oldw, int oldh) {
	super.onSizeChanged(w, h, oldw, oldh);        
	width = w / 8f;            // 1/8th of screen
	height = width;
	//getRect(selX, selY, selRect);    //to keep track of selection cursor
	
 }

public void selectAtTouch(int x, int y) {
	select((int)Math.floor(x/width),(int)Math.floor(y/height));
	
	
}

//sets the selected rectangle member variable to be the one at the index. 
private void select(int x, int y) {
    invalidate(selRect);
    selX = Math.min(Math.max(x,0), 8);
    selY = Math.min(Math.max(y,0), 8);
    getRect(selX, selY, selRect);
    //I dont know that we need to redraw it just by selection.
    //invalidate(selRect);
    Log.d("value of y", Integer.toString(selY));
    Log.d("value of x", Integer.toString(selX));
}
	
@Override
protected void onDraw(Canvas canvas){
super.onDraw(canvas);    
    
       
    mPaint.setColor(0xFF006600);
    canvas.drawRect(0, 0, getWidth(), getHeight(), this.mPaint);

    // Draw the board...
    // Define colors for the grid lines
    mPaint.setColor(0xFFFFFFFF);

    // Draw the  grid lines
    for (int i = 0; i < 9; i++) {
        canvas.drawLine(0, i * height, getWidth(), i * height, this.mPaint);
        canvas.drawLine(0, i * height + 1, getWidth(), i * height + 1, this.mPaint);
        canvas.drawLine(i * width, 0, i * width, getHeight(), this.mPaint);
        canvas.drawLine(i * width + 1, 0, i * width + 1, getHeight(), this.mPaint);            
	
	
}
}}