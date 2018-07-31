package com.example.jin.as_ndk_demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public String name = "test";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        Toast.makeText(this, getMethodFromJNI(), Toast.LENGTH_SHORT).show();
    }


    public String getName() {
        return "111";
    }


    public void fieldFromC(View view) {
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(updateNameFromC());
    }

    public void methodFromC(View view) {
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(getMethodFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String updateNameFromC();

    public native String getMethodFromJNI();

    public native void getArray(int[] arrays);
}
