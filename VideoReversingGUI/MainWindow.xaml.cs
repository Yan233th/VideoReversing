using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Management.Instrumentation;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;

namespace VideoReversingGUI
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow ()
        {
            InitializeComponent ();
        }
        private delegate void DllCallBack (int status);
        [DllImport ("VideoReversingDLL.dll")]
        private static extern int VideoReverse (string input, DllCallBack CallBack);
        [DllImport ("VideoReversingDLL.dll")]
        private static extern int VideoRevCom (string input, DllCallBack CallBack);
        private void ThreadCallBackProcess (int status)
        {
            if (status == 0) MessageBox.Show ("已完成!");
            else MessageBox.Show ("输入路径或文件格式有误!");
            MainWindow1.Dispatcher.Invoke (new Action (delegate {MainWindow1.IsEnabled = true;}));
        }
        private void SelectButton_Click (object sender, RoutedEventArgs e)
        {
            OpenFileDialog dialog= new OpenFileDialog ();
            if (dialog.ShowDialog () == true)
            {
                PathText.Text = dialog.FileName;
            }
        }
        private void ReverseButton_Click (object sender, RoutedEventArgs e)
        {
            PathText.Text = PathText.Text.Replace ("\"", "");
            string originalVideoPath = PathText.Text.Replace ("\\", "/");
            MainWindow1.IsEnabled = false;
            MessageBox.Show ("处理即将开始，请勿重复点击按钮并耐心等待，文件夹中可能有临时文件出现。");
            Thread operate = new Thread (() => VideoReverse (originalVideoPath, ThreadCallBackProcess));
            operate.Start ();
        }

        private void RevComButton_Click (object sender, RoutedEventArgs e)
        {
            PathText.Text = PathText.Text.Replace ("\"", "");
            string originalVideoPath = PathText.Text.Replace ("\\", "/");
            MainWindow1.IsEnabled = false;
            MessageBox.Show ("处理即将开始，请勿重复点击按钮并耐心等待，文件夹中可能有临时文件出现。");
            Thread operate = new Thread (() => VideoRevCom (originalVideoPath, ThreadCallBackProcess));
            operate.Start ();
        }
    }
}
