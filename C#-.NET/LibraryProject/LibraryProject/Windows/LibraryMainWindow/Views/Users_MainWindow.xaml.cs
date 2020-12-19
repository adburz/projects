using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.ComponentModel;

using LibraryProject.Classes.UserClass;
using LibraryProject.Windows.LibraryMainWindow.Views.Admin.UsersTab;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin
{
    /// <summary>
    /// Interaction logic for Users_MainWindow.xaml
    /// </summary>
    public partial class Users_MainWindow : UserControl
    {
        //public BindableCollection<User> users { get; set; }
        public Users_MainWindow()
        {
            InitializeComponent();
           // users = new BindableCollection<User>(Main.Library.GetUsers());
            users_DataGrid.ItemsSource = Main.Library.GetUsers();
            foreach (DataGridColumn c in users_DataGrid.Columns)
            {
                if (c.Header.ToString() == "PESEL")
                {
                    c.Width = new DataGridLength(1.0, DataGridLengthUnitType.SizeToCells);
                }
                else
                {
                    c.Width = new DataGridLength(1.0, DataGridLengthUnitType.Star);
                }
            }

            ICollectionView collectionView = CollectionViewSource.GetDefaultView(users_DataGrid.ItemsSource);
            collectionView.Filter = Filters;
        }
        private bool Filters(object item)
        {
            if (String.IsNullOrEmpty(Name_TextBlock.Text) && String.IsNullOrEmpty(Surname_TextBlock.Text)
                && String.IsNullOrEmpty(Pesel_TextBlock.Text) && String.IsNullOrEmpty(Email_TextBlock.Text))
            {
                return true;
            }
            else
            {
                return ((item as User).Name.IndexOf(Name_TextBlock.Text, StringComparison.OrdinalIgnoreCase) >= 0
                && (item as User).Surname.IndexOf(Surname_TextBlock.Text, StringComparison.OrdinalIgnoreCase) >= 0
                && (item as User).Pesel.IndexOf(Pesel_TextBlock.Text, StringComparison.OrdinalIgnoreCase) >= 0)
                && (item as User).Email.IndexOf(Email_TextBlock.Text, StringComparison.OrdinalIgnoreCase) >= 0;
            }
        }
        private void FilterBoxes_TextChanged(object sender, TextChangedEventArgs e)
        {
            CollectionViewSource.GetDefaultView(users_DataGrid.ItemsSource).Refresh();
        }
        private void AddUser_Clicked(object sender, RoutedEventArgs e)
        {
            if (Application.Current.Windows.OfType<AddUser>().Any())
            {
                return;
            }
            else
            {
                AddUser addUser = new AddUser(Application.Current.MainWindow.Left + 30, Application.Current.MainWindow.Top + 30);
            }
        }
        private void RefreshList(object sender, RoutedEventArgs e)
        {
            users_DataGrid.ItemsSource = null;
            users_DataGrid.ItemsSource = Main.Library.GetUsers();
            CollectionViewSource.GetDefaultView(users_DataGrid.ItemsSource).Refresh();

        }
        private void DeleteUser_Click(object sender, RoutedEventArgs e)
        {
            User selectedUser = (User)users_DataGrid.SelectedItem;
            if (Main.Library.GetLoggedUser() == selectedUser)
            {
                MessageBox.Show("You can't delete yourself!", "Deleting user!", MessageBoxButton.OK, MessageBoxImage.None);
            }
            else
            {
                MessageBoxResult messageBoxResult = MessageBox.Show($"Are you sure to delete this user?\n Selected ID:{selectedUser.UserID}", "Deleting user!",
                                                                    MessageBoxButton.YesNo, MessageBoxImage.Warning, MessageBoxResult.No);
                if (messageBoxResult == MessageBoxResult.Yes)
                {
                    Main.Library.DeleteUser(selectedUser.UserID);
                }
                selectedUser = null;
                users_DataGrid.ItemsSource = null;
                users_DataGrid.ItemsSource = Main.Library.GetUsers();
                CollectionViewSource.GetDefaultView(users_DataGrid.ItemsSource).Refresh();
            }
        }
        private void ScopeUser_Click(object sender, RoutedEventArgs e)
        {
            User selectedUser = (User)users_DataGrid.SelectedItem;

            if (selectedUser == null || Application.Current.Windows.OfType<ScopeUser>().Any())
            {
                return;
            }
            else
            {
                ScopeUser scopeUser = new ScopeUser(selectedUser, Application.Current.MainWindow.Left + 30, Application.Current.MainWindow.Top + 30);
            }
            selectedUser = null;
        }
    }
}
