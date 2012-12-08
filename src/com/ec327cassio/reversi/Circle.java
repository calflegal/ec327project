package com.ec327cassio.reversi;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.Log;
import android.view.View;


public class Circle extends View {
    private final float x;
    private final float y;
    private final int r;
    private final int player;

    private final Paint mPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    
    public Circle(Context context, float x, float y, int r, int player) {
        super(context);
        //mPaint.setColor(0xFFFF0000);
        this.player=player;
        	if (player==1)
        	mPaint.setColor(0xFFFFFFFF);
        	else
        	mPaint.setColor(0xff000000); 
        this.x = x;
        this.y = y;
        this.r = r;
    }
    

 

 
    
    @Override
    protected void onDraw(Canvas canvas){
    	super.onDraw(canvas);
        canvas.drawCircle(x, y, r, mPaint);    
    
       
    }
}
