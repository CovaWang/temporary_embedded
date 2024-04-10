package com.hanheng.dialswitch;
import com.hanheng.dialswitch1.R;

import android.app.Activity;
import android.media.MediaPlayer;
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
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;
import android.widget.ImageView;

//import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.EditText;
 
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
 
public class thirdActivity extends Activity {
	//填写故障部位信息
    private EditText edittext1;
    //填写故障详细信息
    private EditText edittext2;
    //上传按钮
    private Button upload;
    //返回按钮
    private Button fanhui;
    
    //播放音频
  	MediaPlayer mediaPlayer = new MediaPlayer();
  	//控制音量大小
  	public float leftvol, rightvol;
    
    //public String guzhang1;
    //public String guzhang2;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //将该activity与相应的布局文件关联起来
        setContentView(R.layout.third_layout);
        //利用ID来寻找对应的控件
        edittext1 = (EditText)findViewById(R.id.edittext1);
        edittext2 = (EditText)findViewById(R.id.edittext2);
        upload = (Button)findViewById(R.id.upload);
        fanhui = (Button)findViewById(R.id.fanhui);
        
        //进行音频播放器的预处理
        if (mediaPlayer != null && mediaPlayer.isPlaying()) {
            mediaPlayer.stop();
        }
        //设置默认的音量大小
        leftvol = 1;
        rightvol = 1;
        
        //获取启动该Activity的Intent对象
        //Intent intent = getIntent();

        //获取Intent中暂存的数据
        //guzhang1 = intent.getStringExtra("guzhang1");
        //guzhang2 = intent.getStringExtra("guzhang2");
        
        //转到该界面时展示之前已经存储起来的故障信息
        edittext1.setText(secondactivity.guzhang1);
        edittext2.setText(secondactivity.guzhang2);
        
        //为上传按钮设置监听
        upload.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				//上传按钮被点击时播放故障信息上传成功的音频文件
				showSound();
				//利用toast提示故障信息上传成功
				Toast.makeText(getApplicationContext(), "故障信息上传成功！", Toast.LENGTH_SHORT).show();
				//将控件中输入的值赋给相应的存储故障信息的变量
				secondactivity.guzhang1 = edittext1.getText().toString();
				secondactivity.guzhang2 = edittext2.getText().toString();
				
			}
		});
        //为返回按钮设置监听器
        fanhui.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				//Intent intent = new Intent(thirdActivity.this,secondactivity.class);
				//intent.putExtra("guzhang1", guzhang1);
				//intent.putExtra("guzhang2", guzhang2);
				//startActivity(intent);
				
				//当按钮被点击时，要回到上一界面（上一界面未被销毁），那么直接销毁本界面即可
				finish();
			}
		});

    }
    //播放音频
    public void showSound() {
    	//音频播放器预处理
        if (mediaPlayer != null && mediaPlayer.isPlaying()) {
            mediaPlayer.stop();
        }
        mediaPlayer = MediaPlayer.create(this, R.raw.guzhang);
        //设置音量
        mediaPlayer.setVolume(leftvol, rightvol);
        //开始播放
        mediaPlayer.start();
    }
 
    @Override
    protected void onDestroy() {
        super.onDestroy();
        //String s = edittext1.getText().toString();
        //save(s);
    }
 
}
