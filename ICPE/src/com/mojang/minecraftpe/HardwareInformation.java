package com.mojang.minecraftpe;

import android.annotation.SuppressLint;
import android.os.Build;
import com.mojang.minecraftpe.platforms.Platform;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.Reader;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;

@SuppressLint(value={"DefaultLocale"})
public class HardwareInformation {
    private static final CPUInfo cpuInfo = HardwareInformation.getCPUInfo();

    public static String getAndroidVersion() {
        return "Android " + Build.VERSION.RELEASE;
    }

    public static String getCPUFeatures() {
        return cpuInfo.getCPULine("Features");
    }

    /*
     * Enabled aggressive block sorting
     * Enabled unnecessary exception pruning
     * Enabled aggressive exception aggregation
     */
    public static CPUInfo getCPUInfo() {
        BufferedReader bufferedReader;
        new StringBuffer();
        HashMap hashMap = new HashMap();
        boolean bl = new File("/proc/cpuinfo").exists();
        int n = 0;
        if (!bl) return new CPUInfo((Map<String, String>)hashMap, n);
        try {
            String string2;
            bufferedReader = new BufferedReader((Reader)new FileReader(new File("/proc/cpuinfo")));
            Pattern pattern = Pattern.compile((String)"(\\w*)\\s*:\\s([^\\n]*)");
            while ((string2 = bufferedReader.readLine()) != null) {
                Matcher matcher = pattern.matcher((CharSequence)string2);
                if (!matcher.find() || matcher.groupCount() != 2) continue;
                if (!hashMap.containsKey((Object)matcher.group(1))) {
                    hashMap.put((Object)matcher.group(1), (Object)matcher.group(2));
                }
                if (!matcher.group(1).contentEquals((CharSequence)"processor")) continue;
                ++n;
            }
        }
        catch (Exception var5_7) {
            var5_7.printStackTrace();
            return new CPUInfo((Map<String, String>)hashMap, n);
        }
        if (bufferedReader == null) return new CPUInfo((Map<String, String>)hashMap, n);
        try
		{
			bufferedReader.close();
		}
		catch (IOException e)
		{}
        return new CPUInfo((Map<String, String>)hashMap, n);
    }

    public static String getCPUName() {
        return cpuInfo.getCPULine("Hardware");
    }

    public static String getCPUType() {
        return Platform.createPlatform(false).getABIS();
    }

    public static String getDeviceModelName() {
        String string2 = Build.MODEL;
        String string3 = Build.MANUFACTURER;
        if (string2.startsWith(string3)) {
            return string2.toUpperCase();
        }
        return string3.toUpperCase() + " " + string2;
    }

    public static String getLocale() {
        return Locale.getDefault().toString();
    }

    public static int getNumCores() {
        return cpuInfo.getNumberCPUCores();
    }

    public static class CPUInfo {
        private final Map<String, String> cpuLines;
        private final int numberCPUCores;

        public CPUInfo(Map<String, String> map, int n) {
            this.cpuLines = map;
            this.numberCPUCores = n;
        }

        String getCPULine(String string2) {
            if (this.cpuLines.containsKey((Object)string2)) {
                return (String)this.cpuLines.get((Object)string2);
            }
            return "";
        }

        int getNumberCPUCores() {
            return this.numberCPUCores;
        }
    }

}

