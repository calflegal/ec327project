package com.ec327cassio.reversi;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.View;

public class Grid extends View{
    public float tile_width;    // width of one tile
    public float tile_height;    // height on one tile
    public int selX;        // X index of selection
    public int selY;        // Y index of selection
    public final Rect selRect = new Rect();  // selected rectangle
    private final Paint mPaint;
	
public Grid(Context context) {
        super(context);
        this.tile_width = 60;
        this.tile_height = this.tile_width;
        this.mPaint = new Paint();
        
} 



        
private void getRect(int x, int y, Rect rect) {
        rect.set((int)(x = (int) tile_width), (int) (y = (int) tile_height), 
                (int)(x * tile_width + tile_width), (int) (y * tile_height + tile_height));
    }
   
@Override
protected void onSizeChanged(int w, int h, int oldw, int oldh) {
	super.onSizeChanged(w, h, oldw, oldh);        
	tile_width = w / 8f;            // 1/8th of screen
	tile_height = tile_width;
	//getRect(selX, selY, selRect);    //to keep track of selection cursor
	
 }

public void selectAtTouch(int x, int y) {
	select((int)Math.floor(x/tile_width),(int)Math.floor(y/tile_height));
	
	
}

//sets the selected rectangle member variable to be the one at the index. 
public void select(int x, int y) {
    invalidate(selRect);
    selX = Math.min(Math.max(x,0), 8);
    selY = Math.min(Math.max(y,0), 8);
    getRect(selX, selY, selRect);
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
        canvas.drawLine(0, i * tile_height, getWidth(), i * tile_height, this.mPaint);
        canvas.drawLine(0, i * tile_height + 1, getWidth(), i * tile_height + 1, this.mPaint);
        canvas.drawLine(i * tile_width, 0, i * tile_width, getHeight(), this.mPaint);
        canvas.drawLine(i * tile_width + 1, 0, i * tile_width + 1, getHeight(), this.mPaint);            
	
	
}
}}