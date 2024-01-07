using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms.Integration;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using EditorWrapperModule;

namespace ToolEditor
{
    public partial class MainWindow : Window, INotifyPropertyChanged
    {
        #region Binding
        private string testLabel;
        public string TestLabel
        {
            get { return testLabel; }
            set { testLabel = value; OnPropertyChanged(nameof(TestLabel)); }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
        #endregion


        private IntPtr hwnd;
        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = this;
            TestLabel = "Hello";
        }

        #region Action
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            EditorEngine engine = new EditorEngine();
            TestLabel = engine.getX().ToString();
        }
        #endregion

    }
}