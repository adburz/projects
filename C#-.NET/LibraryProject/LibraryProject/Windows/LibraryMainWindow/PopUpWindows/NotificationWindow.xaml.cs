using System.Windows;
using System.Windows.Controls;

namespace LibraryProject.Windows.LibraryMainWindow.PopUpWindows
{
    /// <summary>
    /// Interaction logic for NotificationWindow.xaml
    /// </summary>
    public partial class NotificationWindow : Window
    {
        public NotificationWindow()
        { 
            InitializeComponent();
            this.Show();
            setMessages();

            foreach (DataGridColumn c in Messages_DataGrid.Columns)
            {
                c.Width = new DataGridLength(1.0, DataGridLengthUnitType.Star);
            }
            Main.SetBooksIcon(this);
        }

        private void setMessages()
        {
            Messages_DataGrid.ItemsSource = Main.Library.GetLoggedUser().Notifications;
        }

        private void ClearMessages_Click(object sender, RoutedEventArgs e)
        {
            Main.Library.ClearMessages();
            this.Close();
        }

        private void Close_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
