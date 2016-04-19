using System;
using System.Collections.Generic;
using System.IO;
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

namespace LearnWPF
{
    /// <summary>
    /// Interaction logic for Input.xaml
    /// </summary>
    public partial class Input : Page
    {
        public Input()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, RoutedEventArgs e)
        {
            // Create OpenFileDialog 
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            // Set filter for file extension and default file extension 
            dlg.DefaultExt = ".txt";
            dlg.Filter = "Text documents (.txt)|*.txt";
            // Display OpenFileDialog by calling ShowDialog method 
            Nullable<bool> result = dlg.ShowDialog();
            // Get the selected file name and display in a TextBox 
            if (result == true)
            {
                // Open document 
                string filename = dlg.FileName;
                TextBox1.Text = filename;
            }
        }
        private void Button2_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();       
            dlg.DefaultExt = ".txt";
            dlg.Filter = "Text documents (.txt)|*.txt";
            Nullable<bool> result = dlg.ShowDialog();
            if (result == true)
            {
                // Open document 
                string filename = dlg.FileName;
                TextBox2.Text = filename;
            }
        }
        private void Submit(object sender, RoutedEventArgs e)
        {
            try
            {
                string input1, input2, temp;
                //List<int> xArray = new List<int>();
                //List<int> yArray = new List<int>();
                //List<string> Offices = new List<string>();
                List<Offices> Offices = new List<LearnWPF.Offices>();
                List<string> Office1 = new List<string>();
                List<string> Office2 = new List<string>();
                List<int> Capacity = new List<int>();
                char[] delimiterChars = { ' ' , ','};
                StreamReader file1 = new StreamReader(TextBox1.Text);
                StreamReader file2 = new StreamReader(TextBox2.Text);
                while((input1 = file1.ReadLine()) != null)
                {
                    string[] finalInput = input1.Split(delimiterChars);
                    Offices.Add(new LearnWPF.Offices {Office = finalInput[0], xValue = Int32.Parse(finalInput[1]), yValue = Int32.Parse(finalInput[2]) });
                    //xArray.Add(Int32.Parse(finalInput[1]));
                    //xArray.Add(Int32.Parse(finalInput[2]));
                }
                while((input2 = file2.ReadLine()) != null)
                {
                    string[] finalInput = input2.Split(delimiterChars);
                    Office1.Add(finalInput[0]);
                    Office2.Add(finalInput[1]);
                    Capacity.Add(Int32.Parse(finalInput[2]));
                }
                //Console.WriteLine(yArray[1]);

                file1.Close();

                Plot plot = new Plot(Offices, Office1, Office2, Capacity);
                this.NavigationService.Navigate(plot);

            }
            catch
            {
                
            }
        }
}
}