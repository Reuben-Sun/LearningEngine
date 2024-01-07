using System;
using System.Collections.Generic;
using System.ComponentModel;
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

namespace ToolEditor
{
    public partial class MainWindow : Window, INotifyPropertyChanged
    {
        private string testLabel;
        public string TestLabel
        {
            get { return testLabel; }
            set { testLabel = value; OnPropertyChanged(nameof(TestLabel)); }
        }
        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = this;
            TestLabel = "Hello";
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            // EngineRenderModule engineRenderModule = new EngineRenderModule();
            // TestLabel = engineRenderModule.getX().ToString();
        }
    }
}