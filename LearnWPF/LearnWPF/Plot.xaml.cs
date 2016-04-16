using System;
using System.Collections.Generic;
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
    /// Interaction logic for Plot.xaml
    /// </summary>
    public partial class Plot : Page
    {
        public Plot(List<string> Offices, List<int> xArray, List<int> yArray, List<string> Office1, List<string> Office2, List<int> Capacity)
        {
            InitializeComponent();
            //Console.WriteLine(xArray[1]); //Test. Yep, working

        }

        private double Distance(int x, int y, int x2, int y2)
        {
            double distance, xDiff, yDiff;

            xDiff = Math.Pow(x - x2, 2);
            yDiff = Math.Pow(y - y2, 2);
            distance = Math.Sqrt(yDiff + xDiff);

            return distance;
        }
    }
}
