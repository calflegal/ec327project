package com.ec327cassio.reversi;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.view.View;


public class Grid extends View{
    private float width;    // width of one tile
    private float height;    // height on one tile
    private int selX;        // X index of selection
    private int selY;        // Y index of selection
    private final Rect selRect = new Rect();  // selected rectangle
    private final Paint mPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
	
public Grid(Context context) {
        super(context);
     //   this.width=width;
       // this.height=height;
        
}    
        
private void getRect(int x, int y, Rect rect) {
        rect.set((int)(x = (int) width), (int) (y = (int) height), 
                (int)(x * width + width), (int) (y * height + height));
    }
   
@Override
protected void onSizeChanged(int w, int h, int oldw, int oldh) {
	super.onSizeChanged(w, h, oldw, oldh);        
	width = w / 8f;            // 1/8th of screen
	height = h / 8f;
	getRect(selX, selY, selRect);    //to keep track of selection cursor
	
 }
	
@Override
protected void onDraw(Canvas canvas){
super.onDraw(canvas);    
    
       
	Paint background = new Paint();
    background.setColor(0xFF006600);
    canvas.drawRect(0, 0, getWidth(), getHeight(), background);

    // Draw the board...
    // Define colors for the grid lines
    Paint hilite = new Paint();
    hilite.setColor(0xFFFFFFFF);

    // Draw the minor grid lines
    for (int i = 0; i < 8; i++) {
        canvas.drawLine(0, i * height, getWidth(), i * height, hilite);
        canvas.drawLine(0, i * height + 1, getWidth(), i * height + 1, hilite);
        canvas.drawLine(i * width, 0, i * width, getHeight(), hilite);
        canvas.drawLine(i * width + 1, 0, i * width + 1, getHeight(), hilite);            
	
	
}
}}