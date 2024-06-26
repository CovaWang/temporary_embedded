package com.hanheng.dialswitch;

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
import com.hanheng.a53.seg7.Seg7Class;
//import com.hanheng.dialswitch.R.string;
import com.hanheng.dialswitch1.R;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.Handler.Callback;
import android.os.SystemClock;
import android.provider.MediaStore.Video;
import android.R.integer;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;
import android.graphics.Color;
import android.text.Editable;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.animation.AlphaAnimation;
import android.view.animation.AnimationSet;
import android.view.animation.TranslateAnimation;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;
import android.widget.ImageView;
 
public class MainActivity extends Activity implements OnClickListener{
	private TextView[] text = new TextView[8];
	private ToggleButton[] tb = new ToggleButton[8];
	private Button btnButton;
	private ImageView image;
	private TextView[] textOrder = new TextView[5];
	private boolean flag;
	private boolean isFZero; //记录初始拨码开关是否正确归零
    private EditText password;
    private Button login;
    private Button car1;
    private Button car2;
    private Button car3;
    private String car_div="1";
    
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
        password=(EditText)super.findViewById(R.id.password);//获取用户输入的密码
		initView();
		this.btnButton.setOnClickListener(this);
		for(int i = 0 ; i < tb.length ; i++){
			this.tb[i].setOnClickListener(this);
		}
		login=(Button)findViewById(R.id.login);
		login.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v)
            {//验证用户名密码是否正确
                if(password.getText().toString().equals("123456"))
                {
                    Toast.makeText(getApplicationContext(), "登录成功", Toast.LENGTH_SHORT).show();//提示用户登陆成功
                    patternSwitch(3);
                }
                else if(!password.getText().toString().equals("123456"))
                {
                    Toast.makeText(getApplicationContext(), "密码错误", Toast.LENGTH_SHORT).show();//提示用户用户名或密码错误
                }
                Intent intent = new Intent(MainActivity.this,secondactivity.class);
            	intent.putExtra("car", car_div);
            	//intent.putExtra("guzhang2", guzhang2);
            	startActivity(intent);
            }
        });
		car1=(Button)findViewById(R.id.car1);
		car1.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v)
            {
            	car_div="1";
            }
        });
		
		car2=(Button)findViewById(R.id.car2);
		car2.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v)
            {
            	car_div="2";
            }
        });
		
		car3=(Button)findViewById(R.id.car3);
		car3.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v)
            {
            	car_div="3";
            }
        });
	}
	
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

//	初始化组件
	public void initView(){
		tb[0] = (ToggleButton)findViewById(R.id.toggleButton1);
		tb[1] = (ToggleButton)findViewById(R.id.toggleButton2);
		tb[2] = (ToggleButton)findViewById(R.id.toggleButton3);
		tb[3] = (ToggleButton)findViewById(R.id.toggleButton4);
		tb[4] = (ToggleButton)findViewById(R.id.toggleButton5);
		tb[5] = (ToggleButton)findViewById(R.id.toggleButton6);
		tb[6] = (ToggleButton)findViewById(R.id.toggleButton7);
		tb[7] = (ToggleButton)findViewById(R.id.toggleButton8);	
		text[0] = (TextView)findViewById(R.id.textView1);
		text[1] = (TextView)findViewById(R.id.textView2);
		text[2] = (TextView)findViewById(R.id.textView3);
		text[3] = (TextView)findViewById(R.id.textView4);
		text[4] = (TextView)findViewById(R.id.textView5);
		text[5] = (TextView)findViewById(R.id.textView6);
		text[6] = (TextView)findViewById(R.id.textView7);
		text[7] = (TextView)findViewById(R.id.textView8);
		btnButton=(Button)findViewById(R.id.button1);
		image=(ImageView)findViewById(R.id.imageView1);
		
		textOrder[0] = (TextView)findViewById(R.id.textView11);
		textOrder[1] = (TextView)findViewById(R.id.textView12);
		textOrder[2] = (TextView)findViewById(R.id.textView13);
		textOrder[3] = (TextView)findViewById(R.id.textView14);
		textOrder[4] = (TextView)findViewById(R.id.textView15);

		Log.i("初始化", "消息："+DipClass.Init());
		BeepClass.Init();
		isFZero = true;
		dipInit();
		LedClass.Init();
		int err = Seg7Class.Init();
		FontClass.getInstance();
		
		//stage 0：启动阶段
		//四个LED灯代表的四位bit显示为0001B，代表进入启动阶段
		patternSwitch(0);
		openThread();
	}
	
	//判断拨码开关初始位置是否正确
	public void dipInit(){
		int BEEP_ON = 0;
		if( DipClass.ReadValue() != 0 ){
			isFZero = false;
			BeepClass.IoctlRelay(BEEP_ON); //若不正确，beep声音提示同时触摸屏显示提示信息，等待调整正确
			AlertDialog.Builder dialog = new AlertDialog.Builder(MainActivity.this)
			.setTitle("警告！")
			.setMessage("拨码开关初始未置0，请检查调整确认无误后点击确定")
			.setPositiveButton("确定", new DialogInterface.OnClickListener() {		
				@Override
				public void onClick(DialogInterface dialog, int which) {
					if( DipClass.ReadValue() != 0 ){
						dipInit();
					}
					isFZero = true;
					int BEEP_OFF = 1;
					BeepClass.IoctlRelay(BEEP_OFF);  //拨码开关位置调整正确后关闭蜂鸣器
				}
			});
			dialog.create();
			dialog.show();
		}
	}

	//通过屏幕上开关控制点名
	@Override
	public void onClick(View arg0) {
		// TODO Auto-generated method stub
		int key=arg0.getId();
		switch (key) {
		case R.id.button1:
			exit();
			break;
		case R.id.toggleButton1:
			if(tb[0].isChecked()){
				
				//stage 1：点名阶段·小组摘要
				//四个LED灯代表的四位bit显示为0010B，代表进入点名阶段的小组摘要部分
				patternSwitch(1);
				show_group_number_open();
			}else{
				show_group_number_close();
			}
			break;
		case R.id.toggleButton2:
			if(tb[1].isChecked()){
				show_first_name_lea_open();
			}else{
				show_first_name_lea_close();
			}
			break;
		case R.id.toggleButton3:
			if(tb[2].isChecked()){
				
				//stage 1：点名阶段·组员点名
				//四个LED灯代表的四位bit显示为0100B，代表进入点名阶段的组员点名部分
				patternSwitch(2);
				show_first_name_log_open();
			}else{
				show_first_name_log_close();
			}
			break;
		case R.id.toggleButton4:
			if(tb[3].isChecked()){
				show_first_name_Req_open();
			}else{
				show_first_name_Req_close();
			}
			break;
		case R.id.toggleButton5:
			if(tb[4].isChecked()){
				show_first_name_opt_open();
			}else{
				show_first_name_opt_close();
			}
			break;
		case R.id.toggleButton6:
			if(tb[5].isChecked()){
				show_first_name_sho_open();
			}else{
				show_first_name_sho_close();
			}
			break;
		case R.id.toggleButton7:
			if(tb[6].isChecked()){
				
				//stage 2：深度课设阶段
				//结束点名阶段，四个LED灯代表的四位bit显示为1000B，代表进入深度课设阶段
				if(password.getText().toString().equals("123456"))
                {
                    Toast.makeText(getApplicationContext(), "登录成功", Toast.LENGTH_SHORT).show();//提示用户登陆成功
                    patternSwitch(3);
                }
                else
                {
                    Toast.makeText(getApplicationContext(), "密码错误", Toast.LENGTH_SHORT).show();//提示用户用户名或密码错误
                }
				
			}else{

			}
			break;
		case R.id.toggleButton8:

			break;
		default:
			break;
		}

	}
	
	//拨码开关状态显示
	private int originalVal = 0;
	public int UI_state=0;
	public void computed(int val){

		// 计算差值
		int diff = val - originalVal;
		if (diff < 0) {
			diff = -diff;
			switch(diff) {			
			case(1):changeState(0, 0);break;
			case(2):changeState(1, 0);break;
			case(4):changeState(2, 0);break;
			case(8):changeState(3, 0);break;
			case(16):changeState(4, 0);break;
			case(32):changeState(5, 0);break;
			case(64):changeState(6, 0);break;
			case(128):changeState(7, 0);break;
			}
		}
		else {
			switch(diff) {
			case(1):changeState(0, 1);break;
			case(2):changeState(1, 1);break;
			case(4):changeState(2, 1);break;
			case(8):changeState(3, 1);break;
			case(16):changeState(4, 1);break;
			case(32):changeState(5, 1);break;
			case(64):changeState(6, 1);break;
			case(128):changeState(7, 1);break;
			}
		}			
		
		this.originalVal = val;
	}
	
//	字符串补零
	public String addZero(int b){
		String val = Integer.toBinaryString(b&0xFF);
		String str="";
		if(val.length()<8){
			for(int i=0;i<8-val.length();i++){
				str+=0;
			}			
			return str+=val;
		}
		return val;
	}
	
	//LED灯全关
	public void ledAllOff(){
		LedClass.IoctlLed(0, 0);
		LedClass.IoctlLed(1, 0);
		LedClass.IoctlLed(2, 0);
		LedClass.IoctlLed(3, 0);
	}
	
	//阶段切换
	public void patternSwitch(int pattern){
		ledAllOff();
		switch (pattern) {
		case 0:
			//stage0：启动阶段 0001B
			LedClass.IoctlLed(3, 1);
			break;
        case 1:
        	//stage1：点名阶段·小组摘要 0010B
        	LedClass.IoctlLed(2, 1);
			break;
        case 2:
        	//stage1：点名阶段·组员点名 0100B
        	LedClass.IoctlLed(1, 1);
	        break;
        case 3:
        	endGroupOrder();//浅度课设阶段结束
        	//stage2：深度课设阶段 1000B
        	LedClass.IoctlLed(0, 1);
        	beginGroup(); //深度课设开始
	        break;
		default:
			break;
		}
	}
	
	//浅度课设阶段结束操作：蜂鸣器鸣响+动画（主要点名组件淡出界面，点名标签保留）
	public void endGroupOrder(){
		beepControl(3);  //三声短促的蜂鸣器鸣响“滴滴滴”，表示所有点名结束
		
		AnimationSet as = new AnimationSet(true);
		as.setDuration(1000);
		AlphaAnimation aa = new AlphaAnimation(1,0);
		aa.setDuration(1000);
		as.addAnimation(aa);
		TranslateAnimation ta = new TranslateAnimation(0,0,0,100);
		ta.setDuration(1000);
		as.addAnimation(ta);
		for(int i = 0 ; i < tb.length ; i++){
			tb[i].startAnimation(as);
			text[i].startAnimation(as);
		}
		
		btnButton.startAnimation(as);
		
		image.startAnimation(as);
		
		for(int i = 0 ; i < tb.length ; i++){
			tb[i].setVisibility(tb[i].GONE);
			text[i].setVisibility(text[i].GONE);
		}
		
		btnButton.setVisibility(btnButton.GONE);
		
		image.setVisibility(image.GONE);
	}
	
	public void beginGroup(){
		Intent intent=new Intent(MainActivity.this,secondactivity.class);
        startActivity(intent);
	}
	
	//根据参数number控制蜂鸣器鸣响次数
	public void beepControl(int number){
		int BEEP_ON = 0;
		int BEEP_OFF = 1;
		try {
			for(int i = 0 ; i < number ; i++)
			{
				BeepClass.IoctlRelay(BEEP_ON);
				Thread.sleep(200);
				BeepClass.IoctlRelay(BEEP_OFF);
				Thread.sleep(100);
			}
			} catch (InterruptedException e) { }
	}
	
	public void exit(){		
		AlertDialog.Builder dialog=new AlertDialog.Builder(MainActivity.this);
		dialog.setTitle("程序退出")
		.setMessage("您确定要退出吗？")
		.setIcon(R.drawable.ic_launcher);
		dialog.setCancelable(false);
		dialog.setPositiveButton("确认", new DialogInterface.OnClickListener() {		
			@Override
			public void onClick(DialogInterface dialog, int which) {
				flag=false;
				DipClass.Exit();
				BeepClass.Exit();
				DotArrayClass.Exit();
				LedClass.Exit();
				Seg7Class.Exit();
				MainActivity.this.finish(); //操作结束
			}
		});
		
		dialog.setNegativeButton("取消", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface arg0, int arg1) {
				// TODO Auto-generated method stub
				
			}
		});
		dialog.show();
	}

	//数码管显示
	public void updateText(final float arg){
	    new Thread(new Runnable() {
		public void run() {
				Seg7Class.Seg7Show(arg);
			}
		}).start();
	}
	
	//Author：07
	//Date：2024/04/10
	//Description：显示组号信息。组号"07"的汉字为"七"，转换为4位四进制数为 0013Q
	public void show_group_number_open()
	{
		//模板以数字"0"为例，"0"的汉字为"零"，转换为4位四进制数为 0000Q，请按照本组真实组号对本函数进行修改
		/********请在下方区域修改代码及注释，实现利用点阵和数码管显示本组组号相关信息的功能********/
		
		updateText((float) 0013); //数码管显示4位四进制数
		
		//点阵显示汉字"七"
		String str = "七";  
		byte[][] data = FontClass.getInstance().setContent(str,this.getAssets()); 
		
		/********请在上方区域修改代码及注释，实现利用点阵和数码管显示本组组号相关信息的功能********/
	}
	
	//关闭显示组号信息的数码管
	public void show_group_number_close()
	{
		updateText(0);
	}
	
	//Author：杨冰雪
	//Date：2024/04/10
	//Description：显示组长姓氏信息
	//组长姓氏的汉字为"杨"，该姓氏的拼音首字母小写为"y"，其ASCII码为 0111 1001，转换成4位四进制数为 1231Q
	public void show_first_name_lea_open()
	{
		//模板以"长"为例，"长"的拼音首字母小写为"z"，其ASCII码为 0111 1010B，转换成4位四进制数为1322Q
		//请按照本组组长真实姓氏对本函数进行修改
		/********请在下方区域修改代码及注释，实现利用点阵和数码管显示组长姓氏相关信息的功能********/
		
		updateText((float) 1321); //数码管显示4位四进制数
		
		//标签变为绿色，显示"组长已点名"
		textOrder[0].setBackgroundColor(Color.rgb(0, 255, 0));
		textOrder[0].setText("组长已点名"); 
		
		//点阵显示汉字"刘"
		String str = "杨";
		byte[][] data = FontClass.getInstance().setContent(str,this.getAssets());
		beepControl(2);   //点名正确结束后，蜂鸣器响两声
		
		/********请在上方区域修改代码及注释，实现利用点阵和数码管显示组长姓氏相关信息的功能********/
	}
	
	//关闭显示组长姓氏信息的数码管
	public void show_first_name_lea_close()
	{
		updateText(0);
	}
	
	//Author：彭晓晓
	//Date：2024/04/10
	//Description：显示周志员姓氏信息
	//周志员姓氏的汉字为"彭"，该姓氏的拼音首字母小写为"p"，其ASCII码为 0111 0000B，转换成4位四进制数为 1300Q
	public void show_first_name_log_open()
	{
		/********请在下方区域编写代码及注释，实现利用点阵和数码管显示周志员姓氏相关信息的功能********/
		
		updateText((float) 1300); //数码管显示4位四进制数
		
		//标签变为绿色，显示"周志员已点名"
		textOrder[1].setBackgroundColor(Color.rgb(0, 255, 0));
		textOrder[1].setText("周志员已点名"); 
		
		//点阵显示汉字"彭"
		String str = "彭";
		byte[][] data = FontClass.getInstance().setContent(str,this.getAssets());
		beepControl(2);   //点名正确结束后，蜂鸣器响两声
		
		/********请在上方区域编写代码及注释，实现利用点阵和数码管显示周志员姓氏相关信息的功能********/
	}
	
	//关闭显示周志员姓氏信息的数码管
	public void show_first_name_log_close()
	{
		updateText(0);
	}
	
	//Author：王舒瑀
	//Date：2024/04/10
	//Description：显示需求员姓氏信息
	//需求员姓氏的汉字为"王"，该姓氏的拼音首字母小写为"w"，其ASCII码为 0111 0111B，转换成4位四进制数为 1313Q
	public void show_first_name_Req_open()
	{
		/********请在下方区域编写代码及注释，实现利用点阵和数码管显示需求员姓氏相关信息的功能********/
		
		
		updateText((float) 1313); //数码管显示4位四进制数
		
		//标签变为绿色，显示"需求员已点名"
		textOrder[2].setBackgroundColor(Color.rgb(0, 255, 0));
		textOrder[2].setText("需求员已点名"); 
		
		//点阵显示汉字"王"
		String str = "王";
		byte[][] data = FontClass.getInstance().setContent(str,this.getAssets());
		beepControl(2);   //点名正确结束后，蜂鸣器响两声
		
		/********请在上方区域编写代码及注释，实现利用点阵和数码管显示需求员姓氏相关信息的功能********/
	}
	
	//关闭显示需求员姓氏信息的数码管
	public void show_first_name_Req_close()
	{
		updateText(0);
	}
	
	//Author：王婷睿
	//Date：2024/04/10
	//Description：显示优裁员姓氏信息
	//优裁员姓氏的汉字为"王"，该姓氏的拼音首字母小写为"w"，其ASCII码为 0111 0111B，转换成4位四进制数为 1313Q
	public void show_first_name_opt_open()
	{
		/********请在下方区域编写代码及注释，实现利用点阵和数码管显示优裁员姓氏相关信息的功能********/
		
		updateText((float) 1313); //数码管显示4位四进制数
		
		//标签变为绿色，显示"优裁员已点名"
		textOrder[3].setBackgroundColor(Color.rgb(0, 255, 0));
		textOrder[3].setText("优裁员已点名"); 
		
		//点阵显示汉字"王"
		String str = "王";
		byte[][] data = FontClass.getInstance().setContent(str,this.getAssets());
		beepControl(2);   //点名正确结束后，蜂鸣器响两声
		
		/********请在上方区域编写代码及注释，实现利用点阵和数码管显示优裁员姓氏相关信息的功能********/
	}
	
	//关闭显示优裁员姓氏信息的数码管
	public void show_first_name_opt_close()
	{
		updateText(0);
	}
	
	//Author：王艺琨
	//Date：2024/04/10
	//Description：显示展示员姓氏信息
	//展示员姓氏的汉字为"王"，该姓氏的拼音首字母小写为"w"，其ASCII码为 0111 0111B，转换成4位四进制数为 1313Q
	public void show_first_name_sho_open()
	{
		/********请在下方区域编写代码及注释，实现利用点阵和数码管显示展示员姓氏相关信息的功能********/

		updateText((float) 1313); //数码管显示4位四进制数
		
		//标签变为绿色，显示"展示员已点名"
		textOrder[4].setBackgroundColor(Color.rgb(0, 255, 0));
		textOrder[4].setText("展示员已点名"); 
		
		//点阵显示汉字"王"
		String str = "王";
		byte[][] data = FontClass.getInstance().setContent(str,this.getAssets());
		beepControl(2);   //点名正确结束后，蜂鸣器响两声
		
		/********请在上方区域编写代码及注释，实现利用点阵和数码管显示展示员姓氏相关信息的功能********/
	}
	
	//关闭显示展示员姓氏信息的数码管
	public void show_first_name_sho_close()
	{
		updateText(0);
	}

	//获取到拨码开关：1-显示组号信息;2-显示组长姓氏信息；3-显示周志员姓氏信息；4-显示需求员姓氏信息；5-显示展示员姓氏信息
	public void changeState(int i,int tag){
		if(!isFZero){
			return;
		}
		if(tag==1){
			switch (i) {
			case 0:
				//stage 1：点名阶段·小组摘要
				//四个LED灯代表的四位bit显示为0010B，代表进入点名阶段的小组摘要部分
				patternSwitch(1);
				if(UI_state==1){
					tb[0].setChecked(true);
				}
				show_group_number_open();
				break;
			case 1:
				if(UI_state==1){
					tb[1].setChecked(true);
				}
				show_first_name_lea_open();
				break;
			case 2:
				//stage 1：点名阶段·小组摘要
				//四个LED灯代表的四位bit显示为0100B，代表进入点名阶段的组员点名部分
				patternSwitch(2);
				if(UI_state==1){
					tb[2].setChecked(true);
				}
				show_first_name_log_open();
				break;
			case 3:
				if(UI_state==1){
					tb[3].setChecked(true);
				}
				show_first_name_Req_open();
				break;
			case 4:
				if(UI_state==1){
					tb[4].setChecked(true);
				}
				show_first_name_opt_open();
				break;
			case 5:
				if(UI_state==1){
					tb[5].setChecked(true);
				}
				show_first_name_sho_open();
				break;
			case 6:
				
				//stage 2：深度课设阶段
				//四个LED灯代表的四位bit显示为1000B，代表进入深度课设阶段
				if(UI_state==1){
					tb[6].setChecked(true);
				}
				patternSwitch(3);
				break;
			case 7:
				UI_state=1;
				break;
			default:
				
				break;
			}
		}else{
			switch (i) {
			case 0:
				if(UI_state==1){
					tb[0].setChecked(false);
				}
				show_group_number_close();
				break;
			case 1:
				if(UI_state==1){
					tb[1].setChecked(false);
				}
				show_first_name_lea_close();
				break;
			case 2:
				if(UI_state==1){
					tb[2].setChecked(false);
				}
				show_first_name_log_close();
				break;
			case 3:
				if(UI_state==1){
					tb[3].setChecked(false);
				}
				show_first_name_Req_close();
				break;
			case 4:
				if(UI_state==1){
					tb[4].setChecked(false);
				}
				show_first_name_opt_close();
				break;
			case 5:
				if(UI_state==1){
					tb[5].setChecked(false);
				}
				show_first_name_sho_close();
				break;
			case 6:
				if(UI_state==1){
					tb[6].setChecked(false);
				}
				break;
			case 7:
				UI_state=0;
				break;
			default:
				break;
			}
		}
	}
	
	//初始化按钮文字
	private Handler uiHandler = new Handler(){
		public void handleMessage(Message msg){
			if(msg.what==1){	
				Log.i("获取数据", ""+msg.arg1);
				computed(msg.arg1);
			}
		}
	};
    
public void openThread(){
			if(!flag){
				MyThread thread=new MyThread();
				this.flag=true;
				thread.start();
			}		
	}
	//读取字符线程
	class MyThread extends Thread{
		public void run(){
			int num = 0;				
			while(flag){
				try {				
					Message msgMessage=new Message();
					int value=DipClass.ReadValue();
					msgMessage.what=1;
					msgMessage.arg1=value;
					uiHandler.sendMessage(msgMessage);
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}

			}
		}
	}		
}
