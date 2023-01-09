﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
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
            Process.Start ("cmd.exe", PathText.Text);
        }
    }
}
