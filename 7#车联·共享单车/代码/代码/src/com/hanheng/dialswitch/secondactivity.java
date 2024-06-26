package com.hanheng.dialswitch;

import com.hanheng.dialswitch1.R;
import android.graphics.drawable.GradientDrawable;
import java.util.Random;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.os.Bundle;
import android.widget.EditText;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
//import androidx.appcompat.app.AppCompatActivity;

import android.os.PowerManager;
import android.app.Activity;
import android.os.Bundle;
import android.widget.Button;
import java.io.Console;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.concurrent.Delayed;

import android.os.PowerManager;

import android.content.Context;
import android.content.Intent;

import javax.security.auth.PrivateCredentialPermission;
import com.hanheng.a53.dip.DipClass;
import com.hanheng.a53.beep.BeepClass;
import com.hanheng.a53.dotarray.DotArrayClass;
import com.hanheng.a53.dotarray.FontClass;
import com.hanheng.a53.led.LedClass;
import com.hanheng.a53.seg7.Seg7Class;import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import static android.hardware.SensorManager.SENSOR_DELAY_GAME;
import com.hanheng.dialswitch1.R;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.Handler;
import android.os.Message;
import android.os.Handler.Callback;
import android.os.SystemClock;
import android.provider.MediaStore.Video;
import android.R.integer;
import android.R.string;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;
import android.graphics.Color;
import android.text.Editable;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.AnimationSet;
import android.view.animation.RotateAnimation;
import android.view.animation.TranslateAnimation;
import android.widget.Button;
import android.widget.Chronometer;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;
import android.widget.ImageView;
import android.media.MediaPlayer;

public class secondactivity extends Activity implements SensorEventListener{
	// 数码管组件
	private View display;
	private TextView counterText;
	private Button button1;
	private int temperature = 26;
	
	private ViewGroup baseView = null;
	private Button blackSquare = null;
	
	//开关锁按钮图片
	private ImageView light1;
	private ToggleButton btn1_toggle;
	private boolean btn1_state=true;
	public int[] array={R.drawable.on,R.drawable.off};
	
	//开关控制单车状态显示
	private ImageView warning_img;
	private Button warn1,warn2,warn3;
	public int[] warn_array = {R.drawable.warning1,R.drawable.warning2,R.drawable.warning3};
	
	//电量控制
	private ImageView power_img;
	private TextView text_power;
	public int[] power_array = {R.drawable.power1,R.drawable.power2,R.drawable.power3,R.drawable.power4,R.drawable.power5};
	
	//计时器
	private MyCount mc;
	private TextView text_time;
	private boolean time_state;
	
	//时间与价格计算的计时器
	private Chronometer time_price;
	private boolean tp_state;;  //定义一个参数用来查看状态
	private long p_time = 0;
	
	//停车坐标
	private EditText cpass_text1;
	private EditText cpass_text2;
	
	//停车坐标确定按钮
	private Button cpass_btn;
	
	//地图
	private ImageView cpass_img;
	SensorManager sensor;//SensorManager对象引用
	float currentDegree = 0f; //指南针图片转过的角度
	
	//地图当前位置对应的图片
	private ImageView cpass_sit;
	
	//记录红包车奖励
	private double red_reward=0.0;
	//红包车总上限
	private double reward_sum_max=1.0;
	//红包车单次最高记录
	private double reward_max=0.5;
	//红包车单次最低记录
	private double reward_min=0.1;
	//白包车单次最高惩罚
	private double penalty_max=-0.5;
	//白包车车单次最低惩罚
	private double penalty_min=-0.1;
	//白包车惩罚上限
	private double penalty_sum_max=-1.0;
	
	//存储故障信息
	//public String guzhang1;
	//public String guzhang2;
	static String guzhang1;
	static String guzhang2;
	
	//播放音频
	MediaPlayer mediaPlayer = new MediaPlayer();
	public float leftvol, rightvol;
	public int lock_state;
	
	//休眠待机
	private PowerManager pm;
	private PowerManager.WakeLock wl;
	private boolean PM_state =true;
	
	//加减按钮
	private Button plus_btn;
	private Button sub_btn;
	//当前温度
	private NewText temp;
	
	//选择单车类型
	private String car_div;
	//耗电速度倍数
	private long speed;
	//车辆速度
	private int car_speed;
	
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.second_layout);
		
		//休眠待机
		//获取PowerManager类的一个实例
		pm = (PowerManager)getSystemService(Context.POWER_SERVICE);
		//创建一个PowerManager.WakeLock对象，level为#PARTIAL_WAKE_LOCK
		wl = pm.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK,"My WakeLock");
		
		guzhang1 = "";
		guzhang2 = "";
		//获取启动该Activity的Intent对象
        //Intent intent = getIntent();

        //获取Intent中暂存的数据
        //guzhang1 = intent.getStringExtra("guzhang1");
        //guzhang2 = intent.getStringExtra("guzhang2");
		
		//电量
		power_img = (ImageView)findViewById(R.id.powerdisplay1).findViewById(R.id.power_img);
		text_power = (TextView)findViewById(R.id.powerdisplay1).findViewById(R.id.power_text);
		
		//计时器
	    text_time = (TextView)findViewById(R.id.text_time);
	    time_state=false;
		
		baseView = (ViewGroup) findViewById(R.id.base_view);
		
		blackSquare = new Button(this);
		blackSquare.setText("test");
		blackSquare.setWidth(1024);
		blackSquare.setHeight(600);
		blackSquare.setVisibility(View.INVISIBLE);
		blackSquare.setBackgroundColor(Color.BLACK);
		baseView.addView(blackSquare);
		
		//计时器
		time_price = (Chronometer)findViewById(R.id.time_price_display).findViewById(R.id.chronometer);
		time_price.setFormat("00:%s");
		tp_state = true;
		
		if (mediaPlayer != null && mediaPlayer.isPlaying()) {
            mediaPlayer.stop();
        }
        leftvol = 1;
        rightvol = 1;
        lock_state = 0;

		/**
		  *【承上启下作用说明】乘上：该代码符合车联IIB3.X中关于：“主题效能加法回滚”的课程目标，完善了“电池+脚蹬”、“共享单车”以及“普通单车”三个按钮，定义了相应的点击事件处理。
		  *根据用户从登录界面车辆类型的选择，调整系统的耗电速度和单车的移动速度，并提供提示信息
          *【协同完成人】组长、需求员、优裁员，其中代码部分由组长和优裁员完成按钮选择和相关事件的处理
          *             a.需求员：在深度课设需求三栏文档中详细记录并更新需求，进行精进问解。辅助完善解决代码中的问题。
		  *             b.优裁员：本段代码添加了三种选择按钮消息的显示，辅助组长修改和优化代码，解决在开发过程中遇到的问题
		  *             c.组长：统计代码量：80行 注释：41行 完成车辆类型的选择按钮，以及相关事件的定义。宏观调控整个项目，监督代码的开发与精进过程，确保代码质量和项目
          *【调用说明】本段代码在基座的基础上根据用户选择的车辆类型，来实现不同的耗电速度和移动速度。通过在原有onChronometerTick函数上进行改变，来实现具体事件
          *【主体功能】本段代码的功能是实现车辆选择模式事件的定义，实现车辆选择后的速度变化和消息提示
		  *每种模式对应不同的系统耗电速度和车辆移动速度，通过Intent获得主界面的car1、car2和car3的数据，在按钮点击时给出相应的提示信息
		  *【数据结构与变量说明】在本次代码中主要使用了以下数据结构和变量：
		  *1.car_div：记录单车类型
		  *2.speed：用于改变系统耗电速度
		  *3.car_speed:记录车辆速度
		  *【承上启下作用说明】启下：以此代码段为基础，下一步可以继续完成相应逻辑
         */
        Intent intent = getIntent();
        //获取Intent中暂存的数据
	    car_div = intent.getStringExtra("car");

		//由Intent中的数据来判断单车类型，来选择不同的耗电加速
		//普通单车
	    if(car_div=="1"){
			//回滚到普通态耗电速度
	    	speed=1;
			//回滚到普通态速度
			car_speed=30;
			Toast.makeText(this,"系统已切换到普通态，移动速度和耗电速度最慢"，Toast.LENGTH_LONG).show();
	    }
		//共享单车
	    else if(car_div=="2"){
			//回滚到单体态耗电速度
	    	speed=2;
			//回滚到单体速度
			car_speed=60;
			Toast.makeText(this,"系统已切换到单体态，移动速度和耗电速度中等"，Toast.LENGTH_LONG).show();
	    }
		//电动+脚蹬
	    else if(car_div=="3"){
			//级联态耗电速度
	    	speed=3;
			//级联态速度
			car_speed=100;
			Toast.makeText(this,"系统已切换到级联态，移动速度和耗电速度较快"，Toast.LENGTH_LONG).show();
	    }
	    else{
	    	speed=1;
			car_speed=30;
			Toast.makeText(this,"系统已默认选择普通态，移动速度和耗电速度最慢"，Toast.LENGTH_LONG).show();
	    }
        
		//计时器监听控制电量
		time_price.setOnChronometerTickListener(new Chronometer.OnChronometerTickListener() {
            @Override
            public void onChronometerTick(Chronometer chronometer) {
				//默认显示100%状态的电量图
            	p_time = SystemClock.elapsedRealtime()-speed*time_price.getBase();
				//随时间的变化来主键降低电量
				//我们设置4个阈值，分别为：
				//75% 50% 25% 10%
                if(SystemClock.elapsedRealtime()-speed*time_price.getBase()>=20000){ //一小时的工作时间3600000
                	//此时将图片电量部分显示的图片更改为75%的电量图
					power_img.setImageResource(power_array[1]);
                	text_power.setText("75%");
                }
                if(SystemClock.elapsedRealtime()-speed*time_price.getBase()>=40000){ //一小时的工作时间3600000
                	//此时将图片电量部分显示的图片更改为50%的电量图
					power_img.setImageResource(power_array[2]);
                	text_power.setText("50%");
                }
                if(SystemClock.elapsedRealtime()-speed*time_price.getBase()>=80000){ //一小时的工作时间3600000
					//此时将图片电量部分显示的图片更改为25%的电量图
                	power_img.setImageResource(power_array[3]);
                	text_power.setText("25%");
                }
                if(SystemClock.elapsedRealtime()-speed*time_price.getBase()>=100000){ //一小时的工作时间3600000
					//此时电量过低，可能会导致关锁失败
					//所以需要进行语音强提示，播放电量过低的音频
                	showSound(4);
					//此时将图片电量部分显示的图片更改为《10%的电量图
                	power_img.setImageResource(power_array[4]);
                	text_power.setText("<10%");
                }
                if(SystemClock.elapsedRealtime()-speed*time_price.getBase()>=120000){ //一小时的工作时间3600000
					//系统运行时间超过120000时，系统电量耗尽
                	//强制系统休眠
                	pm.goToSleep(SystemClock.uptimeMillis());
                	
                }
            }
        });
		
		/**
          *编写人：G7Req王舒瑀，G7Log彭晓晓，G7Sho王艺锟
          *编写时间：2024/4/17
          *新增代码量：32行
          *新增注释量：20行
          *为共享单车获得红包奖励的区域添加特殊红色中心区域
          *利用Bitmap在原有地图上添加单车有红包奖励的红色中心区域
		  @param v
        */
		////////////////////52行码释扩充性引导////////////////////
		//指南针
		cpass_text1 = (EditText)findViewById(R.id.compass_display).findViewById(R.id.compass_text1);
		cpass_text2 = (EditText)findViewById(R.id.compass_display).findViewById(R.id.compass_text2);
		//输入还车坐标
		cpass_text1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
            	String userInput = cpass_text1.getText().toString();
            }
        });
		
        //获取地图照片
		cpass_img = (ImageView)findViewById(R.id.compass_display).findViewById(R.id.compass_img);
		
		//获取当前位置图片
		cpass_sit=(ImageView)findViewById(R.id.compass_display).findViewById(R.id.compass_sit);
		
		//获取当前位置的布局参数
		RelativeLayout.LayoutParams sit_params=(RelativeLayout.LayoutParams)cpass_sit.getLayoutParams();
		
		//生成随机的位置坐标
		int minX=90;
		int maxX=330;
		int minY=85;
		int maxY=210;
		//生成随机的x和y坐标
		Random random=new  Random();
		int randomX=random.nextInt(maxX-minX+1)+minX;
		int randomY=random.nextInt(maxY-minY+1)+minY;
		
		//设置新的左边距
		sit_params.leftMargin=randomX; 
		//设置新的上边距
		sit_params.topMargin=randomY; 
		
		cpass_sit.setLayoutParams(sit_params);
		
		/*----------------白包区域绘制------------------*/
		// 假设你有一个名为bitmap的Bitmap对象
		Bitmap bitmapw = BitmapFactory.decodeResource(getResources(), R.drawable.map);

		// 创建一个新的Bitmap对象，作为绘制区域
		Bitmap mutableBitmapw = bitmapw.copy(Bitmap.Config.ARGB_8888, true);

		// 创建一个Canvas对象，用于在Bitmap上绘制
		Canvas canvasw = new Canvas(mutableBitmapw);

		// 创建一个Paint对象，用于指定绘制属性
		Paint paintw = new Paint();
		// 设置颜色为透明红色（ARGB格式，红色最大，透明度最大）
		paintw.setColor(Color.argb(128, 200, 200, 200)); // 透明度为128，红色为255，绿色和蓝色为0
		paintw.setStyle(Paint.Style.FILL); // 填充矩形区域
		
		//中心区域左上坐标
		int Rect_leftw=650;
		//中心区域左上纵坐标
		int Rect_upw=350;
		//中心区域右下横坐标
		int Rect_rightw=850;
		//中心区域右下纵坐标
		int Rect_downw=650;
		// 绘制矩形区域
		Rect rectw = new Rect(Rect_leftw, Rect_upw, Rect_rightw, Rect_downw);
		canvasw.drawRect(rectw, paintw);

		/*---------------红包区域绘制---------------*/
		// 假设你有一个名为bitmap的Bitmap对象
		Bitmap bitmapr = BitmapFactory.decodeResource(getResources(), R.drawable.map);

		// 创建一个新的Bitmap对象，作为绘制区域
		Bitmap mutableBitmapr = bitmapr.copy(Bitmap.Config.ARGB_8888, true);

		// 创建一个Canvas对象，用于在Bitmap上绘制
		Canvas canvasr = new Canvas(mutableBitmapr);

		// 创建一个Paint对象，用于指定绘制属性
		Paint paintr = new Paint();
		// 设置颜色为透明红色（ARGB格式，红色最大，透明度最大）
		paintr.setColor(Color.argb(128, 250, 0, 0)); // 透明度为128，红色为255，绿色和蓝色为0
		paintr.setStyle(Paint.Style.FILL); // 填充矩形区域
		
		//中心区域左上坐标
		int Rect_leftr=310;
		//中心区域左上纵坐标
		int Rect_upr=200;
		//中心区域右下横坐标
		int Rect_rightr=480;
		//中心区域右下纵坐标
		int Rect_downr=550;
		// 绘制矩形区域
		Rect rectr = new Rect(Rect_leftr, Rect_upr, Rect_rightr, Rect_downr);
		canvasw.drawRect(rectr, paintr);

		// 将绘制后的Bitmap对象显示在ImageView或其他视图中
		cpass_img.setImageBitmap(mutableBitmapw);
		
		/*----------------------------------------------*/
		
		sensor = (SensorManager) getSystemService(SENSOR_SERVICE);//获得SensorManager
		//获取方向传感器
        Sensor type_compass = sensor.getDefaultSensor(Sensor.TYPE_ORIENTATION);
        sensor.registerListener(this, type_compass, SENSOR_DELAY_GAME);
		
		//单车开关锁按钮
		btn1_toggle=(ToggleButton)findViewById(R.id.display1).findViewById(R.id.togglebtn1);
		light1=(ImageView)findViewById(R.id.display1).findViewById(R.id.imgv1);
		
		//单车状态控制开关
		warning_img = (ImageView)findViewById(R.id.warning_display).findViewById(R.id.warning_img);
		warn1 = (Button)findViewById(R.id.warning_display).findViewById(R.id.warn_btn1);
		warn2 = (Button)findViewById(R.id.warning_display).findViewById(R.id.warn_btn2);
		warn3 = (Button)findViewById(R.id.warning_display).findViewById(R.id.warn_btn3);
		
		// 数码管组件初始化
		display = (View) findViewById(R.id.display5);
		counterText = (TextView) display.findViewById(R.id.counterText);
		int err = Seg7Class.Init();
		
		///////////////////////88行码释扩充性引导///////////////////////
		//停车坐标确定按钮
		cpass_btn=(Button)findViewById(R.id.compass_display).findViewById(R.id.compass_btn);

		/**
		  *【承上启下作用说明】承上：该段代码符合该阶段“共享维护”的课程目标，根据红包车和白包车的特点设置了红包车和白包车的区域，在红包车区域内停车可以得到相应的奖
		  *                        励，同理在白包车区域内停车会获得相应的惩罚。这些指向了我们“共享维护”的课程目标，做到人人都参与进共享维护，降低相应的维护代价，
		  *					       促进人车共享骑行与维护共同体生态。
          *【协同完成人】组长、需求员、优裁员，其中代码部分由组长和优裁员完成红包车和白包车区域划分以及相应的奖励和惩罚。
          *             a.需求员：本段代码关联三栏文档中的第9页的填写要求，完成红包车和白包车区域的定义以及实现自定义坐标的输入
		  *             b.优裁员：本段代码总体指定了红包车和白包车的区域，给出了相应的奖惩操作
		  *             c.组长：统计代码量：124行 注释：79行 完成坐标输入的确定按钮，以及停车地点的位置判断，并给予相应的奖惩。
          *【调用说明】本段代码在基座的基础上新增加了停车坐标坐标确定按钮，设计了询问是否按照规定路线行驶的消息框，定义了红包车和白包车的停车区域
          *【主体功能】函数的作用是通过用户的停车坐标来判断单车所处的区域（红包车或者白包车区域）来给予相应的奖励和惩罚。在此基础上在用户开始骑行前询问是否按照规划
		  *           路线骑行，并根据相应决定（是或否），给予相应的奖励。
		  *【数据结构与变量说明】
		  *@param v，dialog，which
		  *【承上启下作用说明】启下：以本次目标以及上一条精进路线为指导，完成具体的代码实现。比如根据用户投票，进行红包车和白包车区域的修改
         */
		//询问是否按照规定路线行驶，按照规定路线可能获得红包车
		cpass_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
            	// 创建 AlertDialog.Builder 对象
                AlertDialog.Builder builder = new AlertDialog.Builder (secondactivity.this);
                builder.setTitle("路线规划");
                builder.setMessage("您是否打算按照规定路线行驶？如果按照规定路线行驶可能获得红包！");
                
                // 添加“是”按钮，并设置点击事件监听器
                builder.setPositiveButton("是", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                    	//判断红包奖励是否已经达到上限
                    	if(red_reward>=reward_sum_max){
                    		Toast.makeText(getApplicationContext(), "红包已达上限！！！", Toast.LENGTH_SHORT).show();
                    	}
                    	else{
                    		//创建一个Random对象
                        	Random random=new Random();
                        	//生成0.1-0.5之间的随机数
                        	double randomNum=reward_min+(reward_max-reward_min)*random.nextDouble();
                            //随机产生红包车
                        	red_reward+=randomNum;
                        	Toast.makeText(getApplicationContext(), 
                        			"获得红包奖励："+randomNum+"累计金额为："+red_reward, Toast.LENGTH_LONG).show();
                    	}
                    }
                });

                // 添加“否”按钮，并设置点击事件监听器
                builder.setNegativeButton("否", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        //没有任何奖励
                    	red_reward+=0;
                    }
                });

                // 创建并显示对话框
                AlertDialog dialog = builder.create();
                dialog.show();
                
                /*更新单车坐标*/
          	  //获取当前位置图片
                 ImageView cpass_sit_new=(ImageView)findViewById(R.id.compass_display).findViewById(R.id.compass_sit);
                //获取当前位置的布局参数
          		RelativeLayout.LayoutParams sit_params_new=(RelativeLayout.LayoutParams)cpass_sit_new.getLayoutParams();
          	  // 获取输入的数字字符串 
          		EditText editText1=(EditText)findViewById(R.id.compass_display).findViewById(R.id.compass_text1);
          		EditText editText2=(EditText)findViewById(R.id.compass_display).findViewById(R.id.compass_text2);
          		String inputText1 = editText1.getText().toString();
          		String inputText2 = editText2.getText().toString();
          	  // 尝试将输入的数字字符串转换为整形
          		int intValue1 = Integer.parseInt(inputText1);
          		int intValue2 = Integer.parseInt(inputText2);
          	  //图上坐标换算
          		int Value1=intValue1*7/25-7;
          		int Value2=intValue2*18/55+10;
          	  //设置单车坐标参数
          		sit_params_new.leftMargin=Value1; 
          		sit_params_new.topMargin=Value2;
          	 //更新坐标
          		cpass_sit_new.setLayoutParams(sit_params_new);
          		
          	// 判断更新坐标的位置
                if((intValue1>650&&intValue1<850)&&(intValue2>350&&intValue2<650)){ //判断为白包车
                	if(red_reward<=penalty_sum_max){
                		Toast.makeText(getApplicationContext(), "白包已达上限！！！", Toast.LENGTH_SHORT).show();
                	}
                	else{
                		//创建一个Random对象
                    	Random random=new Random();
                    	//生成0.1-0.5之间的随机数
                    	double randomNum=penalty_min+(penalty_max-penalty_min)*random.nextDouble();
                        //随机产生红包车
                    	red_reward+=randomNum;
                    	//弹框显示
                    	Toast.makeText(getApplicationContext(), 
                    			"获得白包惩罚："+randomNum+"累计金额为为："+red_reward, Toast.LENGTH_LONG).show();
                	}
                }
                else if((intValue1>310&&intValue1<480)&&(intValue2>200&&intValue2<550)) 
                { 
                	if(red_reward>=reward_sum_max){
                		Toast.makeText(getApplicationContext(), "红包已达上限！！！", Toast.LENGTH_SHORT).show();
                	}
                	else{
                		//获取红包奖励
                    	//创建一个Random对象
                    	Random random=new Random();
                    	//生成0.1-0.5之间的随机数
                    	double randomNum=reward_min+(reward_max-reward_min)*random.nextDouble();
                        //随机产生红包车
                    	red_reward+=randomNum;
                    	//弹框显示
                    	Toast.makeText(getApplicationContext(), 
                    			"获得红包奖励："+randomNum+"累计金额为为："+red_reward, Toast.LENGTH_LONG).show();
                	}
                }
                else{
                	Toast.makeText(getApplicationContext(), "无奖励！！！", Toast.LENGTH_SHORT).show();
                }
            }
        });
		
		/**
		  *【承上启下作用说明】乘上：该代码符合车联IIB3.X中关于：“主题效能加法回滚”的课程目标，添加了“电池+脚蹬”、“共享单车”以及“普通单车”三个按钮。除此之外还添加了温度上升和降低按钮，定义了相应的点击事件的处理。通过点击温度“+”或者温度“-”按钮达到将温度升高或者降低的效果
          *【协同完成人】组长、需求员、优裁员、周志员、展示员，其中代码部分由组长和优裁员完成按钮添加和相关事件的定义
          *             a.需求员：在课前课后进行小组本周计划提交，在深度课设需求三栏文档中详细记录并更新小组的需求，确定本周功能模式的定义，确立回滚中的功能需要，确保所有成员对项目的需求，将小组的工作进度和问题通过issue及board进行上报。
		  *             b.优裁员：本段代码添加了三种单车按钮的添加，辅助组长修改和优化代码，解决在开发过程中遇到的问题
		  *             c.组长：统计代码量：85行 注释：38行 完成温度的升降按钮，以及相关事件的定义。宏观调控整个项目，监督代码的开发与精进过程，确保代码质量和项目进度
		  *             d.周志员：除了完成小组8XML文档的填写，还需记录本周的课设进度，协助小组成员完善代码设计，并详细记录代码的所有改动，以便于后续的追踪与调试
		  *             e：展示员：将负责把本周实现的代码功能进行复现，并及时记录小组的成果，并将这些成果汇总，以便于后续的展示
          *【调用说明】本段代码在基座的基础上新增加了温度升降的按钮，实现了3.X中不同环境中温度的变化。
          *【主体功能】函数的作用是通过点击温度“+”按钮来增加目前的温度，每点击一次增加一度，并将其显示在屏幕中；同理通过点击温度“-”按钮来降低目前温度，每点击一次降低一度，可以通过点击达到零下的温度。三个不同类型单车的按钮因为该界面中位置不足，设置在mainactivity界面，在用户登录之前可以通过点击来选择想要的车型。
		  *【数据结构与变量说明】在本次代码中主要使用了以下数据结构和变量：
		  *1.plus_btn、sub_btn：分别对应温度加减按钮
		  *2.temp：用于显示实时温度变化
		  *3.car1、car2、car3（mainactivity界面）：分别对应三种不同类型的车“电池+脚蹬”、“共享单车”以及“普通单车”
		  *【承上启下作用说明】启下：以此代码段为基础，下一步可以实现温度变化后的相关变化，初次之外还可以实现识别用户所选类型车辆，如没有选择将给出默认车辆，并根据所选类型车辆调整相关的耗电速度，并给出相关提示信息。
         */
		//温度加减按钮
		plus_btn=(Button)findViewById(R.id.temp_btn_plus);
		sub_btn=(Button)findViewById(R.id.temp_btn_sub);
		//显示温度
		temp=(NewText)findViewById(R.id.counterText);
		//升高温度
		plus_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
            	String Cur_Temp_Str = temp.getText().toString();
            	int Cur_Temp_Int=Integer.parseInt(Cur_Temp_Str);
            	Cur_Temp_Int++;
            	String Cur_Temp=Integer.toString(Cur_Temp_Int);
            	temp.setText(Cur_Temp);
            }
        });
		//降低温度
		sub_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
            	String Cur_Temp_Str = temp.getText().toString();
            	int Cur_Temp_Int=Integer.parseInt(Cur_Temp_Str);
            	Cur_Temp_Int--;
            	String Cur_Temp=Integer.toString(Cur_Temp_Int);
            	temp.setText(Cur_Temp);
            }
        });
		
		//还车退出按钮
		button1=(Button)findViewById(R.id.button2_1);
		
		button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
  
            	Toast.makeText(getApplicationContext(), 
            			"成功退出，单车骑行使用时间： "+p_time/1000+" 秒，需支付"+((p_time > 7200000 ? (1.5+(p_time-7200000)/6000000) : 1.5)-red_reward)+"元！", 
            			Toast.LENGTH_LONG).show();
				//播放还车成功的音频
            	showSound(3);
				//销毁本界面
                finish();
            }
        });
		
		
		//单车开关锁显示切换
		// 在单车开关按钮处设置监听触发器
		btn1_toggle.setOnClickListener(new View.OnClickListener() {
			// 重写click点击函数
			@Override
			public void onClick(View v) {
				// 根据btn_state去判断当前的开关锁时初次开关锁
				// 还是已经开关锁后的临时停车情况
				if(btn1_state){
					if(tp_state){
						// 根据单车开关进行骑行 
						// 进而开始进行计费计算
						time_price.setBase(SystemClock.elapsedRealtime());
					}
					// 开始计费时间计算
					time_price.start();
					// 改变开关btn1_toggle的状态
					btn1_toggle.setChecked(true);
					// 更改显示的图片  
					// 从array[]数组中进行选择目标图片
					light1.setImageResource(array[1]);
					btn1_state=false;
					// 临时停车倒计时的重新开始
					// 恢复成null状态
					if(time_state){
						mc.cancel();
						mc=null;
					}
				}
				else{
					// 根据Boolean的状态选择判断
					// 停止骑行收费的计时
					time_price.stop();
					tp_state = false;
					// 改变开关btn1_toggle的状态
					btn1_toggle.setChecked(false);
					// 更改显示的图片  
					// 从array[]数组中进行选择目标图片
					light1.setImageResource(array[0]);
					btn1_state=true;
					time_state=true;
					if(mc==null){
						// 开始进行倒计时
						// 设定为300s  5分钟的自由时间
						mc = new MyCount(300000,1000);
					}
					mc.start();
				}
				// 开关锁的语音麦克风播放
				if(lock_state == 0){
					lock_state = 1;
					showSound(1);
				}
				else{
					lock_state = 0;
					showSound(2);
				}
			}
		});
		
		//单车状态显示切换
		warn1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// 单车良好状态下的显示
				// 弹窗弹出”单车硬件设备良好“的消息
				warning_img.setImageResource(warn_array[0]);
				Toast.makeText(getApplicationContext(), "单车硬件设备良好", Toast.LENGTH_SHORT).show();
			}
		});
		warn2.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// 单车状态轻微损坏下的显示
				// 弹窗弹出”单车硬件设备存在部分故障，但仍可骑行“的消息
				warning_img.setImageResource(warn_array[1]);
				Toast.makeText(getApplicationContext(), "单车硬件设备存在部分故障，但仍可骑行", Toast.LENGTH_SHORT).show();
			}
		});
		warn3.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// 单车完全损坏下的状态显示
				// 弹窗弹出”单车硬件设备存在骑行危险，需进行故障上报“的消息
				warning_img.setImageResource(warn_array[2]);
				Toast.makeText(getApplicationContext(), "单车硬件设备存在骑行危险，需进行故障上报", Toast.LENGTH_SHORT).show();
				// 单车损坏严重 
				// 需要对故障进行上报处理
				// 跳转到第三界面  上报故障信息
				Intent intent = new Intent(secondactivity.this,thirdActivity.class);
				//intent.putExtra("guzhang1", guzhang1);
				//intent.putExtra("guzhang2", guzhang2);
				startActivity(intent);
				
			}
		});
		
	}
	
	// 麦克风显示提示音
	public void showSound(int n) {
		// 防止声音冲突播放
        if (mediaPlayer != null && mediaPlayer.isPlaying()) {
            mediaPlayer.stop();
        }
		// n = 1 2 3 4
		// 四种状态下的不同选择
        if(n == 1){
        	mediaPlayer = MediaPlayer.create(this, R.raw.kaisuo);
        }
        else if(n == 2){
        	mediaPlayer = MediaPlayer.create(this, R.raw.guansuo);
        }
        else if(n == 3){
        	mediaPlayer = MediaPlayer.create(this, R.raw.huanche);
        }
        else if(n == 4){
        	mediaPlayer = MediaPlayer.create(this, R.raw.dianliang);
        }
        mediaPlayer.setVolume(leftvol, rightvol);
        mediaPlayer.start();
    }
	
	// 指南针图片的指针转动效果实现
	@Override
    public void onSensorChanged(SensorEvent event) {
		// 获取设备上的传感器
        int sensorType = event.sensor.getType();
        switch (sensorType) {
            case Sensor.TYPE_ORIENTATION:
				// 得到旋转角度
                float degree = event.values[0]; //获取z转过的角度
				// 设定角度的显示格式
				// 保留 1 位小数
                cpass_text1.setText(String.format("%.1f", event.values[0]));
                cpass_text2.setText(String.format("%.1f", event.values[0]));
                //穿件旋转动画
				// 使用 RotateAnimation 的方法
                RotateAnimation ra = new RotateAnimation(currentDegree, -degree, Animation.RELATIVE_TO_SELF, 0.5f
                        , Animation.RELATIVE_TO_SELF, 0.5f);
                ra.setDuration(100);//动画持续时间
                cpass_img.startAnimation(ra);
				// 变更当前角度 为下次旋转做准备
                currentDegree = -degree;
                break;
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
    }

	// 通过按键模拟温度升高或下降的情况
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		// 温度升高的情况下
		if (keyCode== KeyEvent. KEYCODE_DPAD_UP) {
			// 弹窗提示
			Toast.makeText(this, "温度升高", Toast.LENGTH_SHORT).show();
			temperature += 1;
			if(temperature >= 50 || temperature <= -40){
				blackSquare.setVisibility(View.VISIBLE);
				//强制系统休眠
				pm.goToSleep(SystemClock.uptimeMillis());
				PM_state=false;
			} else{
				blackSquare.setVisibility(View.INVISIBLE);
				//强制唤醒系统
				if(!PM_state){
					pm.wakeUp(SystemClock.uptimeMillis());
					PM_state=true;
				}
			}
			updateText(temperature);
			return true;
		}

		else if (keyCode == KeyEvent. KEYCODE_DPAD_DOWN) {
			Toast.makeText(this, "温度下降", Toast.LENGTH_SHORT).show();
			temperature -= 1;
			if(temperature >= 50 || temperature <= -40){
				blackSquare.setVisibility(View.VISIBLE);
				//强制系统休眠
				pm.goToSleep(SystemClock.uptimeMillis());
				PM_state=false;
			} else{
				blackSquare.setVisibility(View.INVISIBLE);
				//强制唤醒系统
				if(!PM_state){
					pm.wakeUp(SystemClock.uptimeMillis());
					PM_state=true;
				}
			}
			updateText(temperature);
			return false;
		}

		return super.onKeyDown(keyCode, event);
	}
	
	// 更新数码管内容
	public void updateText(final int arg){
		String str = addZero(String.valueOf(arg));
		this.counterText.setText(str);
		/**
		 * 请在此补充硬件调用函数
		*/
		new Thread(new Runnable() {
			public void run() {
				Seg7Class.Seg7Show(arg);
			}
		}).start();
	}
		
	// 不足4位进行补零
	// 数码管在进行显示的时候 在某些时刻可能位数较少
	// 这种情况下  可采取补零的方式使其规范化
	public String addZero(String content) {
		// 需要额外补齐的位数
		int count = 4 - content.length();
		StringBuffer sb = new StringBuffer();
		// append方式进行补零
		for (int i = 0; i < count; i++) {
			sb.append("0");
		}
		StringBuffer str = sb.append(content);
		// 返回最终的结果数码显示
		return str.toString();
	}
	
	// 此处为对计时器的使用
	class MyCount extends CountDownTimer {
		// extend继承CountDownTimer进行使用
        public MyCount(long millisInFuture, long countDownInterval) {
            super(millisInFuture, countDownInterval);
        }
		// 重写结束onfinish()
        @Override
        public void onFinish() {
        	finish();
        }
		// 计时器倒计时功能显示
        @Override
        public void onTick(long millisUntilFinished) {
        	text_time.setText("距离自动还车退出还有" + millisUntilFinished / 1000 + "秒");
        }
    }
	
	// 活动销毁函数onDestory()
	@Override
    protected void onDestroy() {
        super.onDestroy();
    }
	
}
