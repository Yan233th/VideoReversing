using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
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
        ////[DllImport ("VideoReversingDLL.dll")]
        ////static extern IntPtr GetFileName (string input);
        ////[DllImport ("VideoReversingDLL.dll")]
        ////static extern IntPtr GetFilePath (string input);
        [DllImport ("VideoReversingDLL.dll")]
        static extern bool VideoReverse (string input);
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
            string originalVideoPath = PathText.Text.Replace ("\\", "/");
            MessageBox.Show ("处理即将开始，请勿重复点击按钮并耐心等待，文件夹中可能有临时文件出现。");
            if (VideoReverse (originalVideoPath) == true)
                MessageBox.Show ("输入路径或文件格式有误!");
            //IntPtr filePath = GetFilePath (originalVideoPath);
            //PathText.Text = Marshal.PtrToStringAnsi (filePath);
        }
    }
}
