package com.ec327cassio.reversi;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;


public class Circle extends View {
    private final float x;
    private final float y;
    private final int r;
    private final int player;

    public final Paint mPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    
    public Circle(Context context, float x, float y, int r, int player) {
        super(context);
        this.player=player;
        	if (this.player==1)
        	mPaint.setColor(Color.WHITE);
        	else
        		//black
        	mPaint.setColor(Color.BLACK);
        this.x = x;
        this.y = y;
        this.r = r;
    }
    

    //draws circles
    @Override
    protected void onDraw(Canvas canvas){
    	super.onDraw(canvas);
        canvas.drawCircle(x, y, r, mPaint);    
    
       
    }
}
