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

    private int[] arr = {5, 9 ,3, 21, 87, 2};

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

    public void sort(View view) {
        TextView tv = findViewById(R.id.sample_text);

        getArray(arr);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i]).append(",");
        }
        tv.setText(sb.toString());
    }

    public void exception(View view) {
        TextView tv = findViewById(R.id.sample_text);
        try {
            exception();
        } catch (Exception e) {
            tv.setText(e.getMessage());
        }

//        tv.setText();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String updateNameFromC();

    public native String getMethodFromJNI();

    public native void getArray(int[] arrays);

    public native void getLocalReference();

    public native void exception();



}
