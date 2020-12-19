using System.Windows;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin.UsersTab
{
    /// <summary>
    /// Interaction logic for ScopeUser_SendNotification.xaml
    /// </summary>
    public partial class ScopeUser_SendNotification : Window
    {
        private uint userID { get; set; }
        public ScopeUser_SendNotification(uint _userID, double _left, double _top)
        {
            userID = _userID;
            InitializeComponent();
            this.Left = _left;
            this.Top = _top;
            Main.SetBooksIcon(this);
            this.Show();
           
        }

        private void SendNotification_Click(object sender, RoutedEventArgs e)
        {
            string message = Message_TextBox.Text.ToString();
            Main.Library.AddNotification(message, userID);
            this.Close();
        }
    }
}
