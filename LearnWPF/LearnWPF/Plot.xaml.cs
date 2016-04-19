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
        public Plot(List<Offices> Offices, List<string> Office1, List<string> Office2, List<int> Capacity)
        {
            InitializeComponent();
            //Console.WriteLine(xArray[1]); //Test. Yep, working
            List<Offices> ReachedNodes = new List<Offices>();
            List<Offices> PreviousNode = new List<Offices>();
            List<Offices> UnreachedNodes = new List<Offices>();
            double min = -999;
            double CurrDistance;
            string minOffice = "";
            string CurrOffice;

            PreviousNode[0].Office = "0";
            PreviousNode[0].xValue = 0;
            PreviousNode[0].yValue = 0;
            ReachedNodes[0] = Offices[0];
            for(int x = 1; x <= Offices.Count; x++)
            {
                UnreachedNodes[x] = Offices[x];
            }

            while (UnreachedNodes.Count != 0)
            {
                for(int y = 0; y < ReachedNodes.Count; y++) //iterate through reachednodes 
                {
                    for(int x = 0; x < UnreachedNodes.Count; x++)
                    {
                        CurrDistance = Distance(ReachedNodes[y].xValue, ReachedNodes[y].yValue, UnreachedNodes[x].xValue, UnreachedNodes[x].yValue);
                        CurrOffice = UnreachedNodes[x].Office;
                        if(min == -999)
                        {
                            min = CurrDistance;
                            minOffice = UnreachedNodes[x].Office;
                        }
                        else if(CurrDistance < min)
                        {
                            min = CurrDistance;
                            minOffice = UnreachedNodes[x].Office;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                min = -999;
                UnreachedNodes.Remove(new LearnWPF.Offices() { Office = minOffice });
                var newNode = Offices.Where(x => x.Office == minOffice);
                ReachedNodes.AddRange(newNode);
                PreviousNode.Add(ReachedNodes[PreviousNode.Count - 1]);
            }

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
