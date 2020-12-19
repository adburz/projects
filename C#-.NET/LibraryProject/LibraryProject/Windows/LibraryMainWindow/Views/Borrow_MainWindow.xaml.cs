using LibraryProject.Classes.Rents;
using LibraryProject.Classes.UserClass;
using System;
using System.ComponentModel;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin
{
    /// <summary>
    /// Interaction logic for Expired_MainWindow.xaml
    /// </summary>
    public partial class Borrow_MainWindow : UserControl
    {
        ICollectionView Source { get; set; }
        public Borrow_MainWindow()
        {
            InitializeComponent();

            if (Main.Library.GetLoggedUser().Role == ERole.Client)
            {
                Delete_Button.Visibility = Visibility.Hidden;
                Notification_Button.Visibility = Visibility.Hidden;
            }
            else
            {
                Expired_CheckBox.Visibility = Visibility.Visible;
                Notification_Button.Visibility = Visibility.Visible;
            }

            setListData();
            setCellsSize();

        }
        private void setListData()
        {
            if (Main.Library.GetLoggedUser().Role == ERole.Admin)
            {
                expired_DataGrid.ItemsSource = Main.Library.GetHires();
            }
            else
            {
                expired_DataGrid.ItemsSource = Main.Library.GetHires().Where(x => x.UserID == Main.Library.GetLoggedUser().UserID);
            }
            Source = CollectionViewSource.GetDefaultView(expired_DataGrid.ItemsSource);
            Source.Filter = ExpiredFilter;
        }
        private bool ExpiredFilter(object item)
        {
            if (String.IsNullOrEmpty(HireIDFilter_TextBox.Text)
                && String.IsNullOrEmpty(ISBNFilter_TextBox.Text)
                && Expired_CheckBox.IsChecked is false)
            {
                return true;
            }
            else
            {
                if (Expired_CheckBox.IsChecked is true)
                {
                    return ((item as Hire).HireID.ToString().IndexOf(HireIDFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                        && (item as Hire).ISBN.IndexOf(ISBNFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0)
                        && (item as Hire).isExpired == true;
                }
                else
                {
                    return ((item as Hire).HireID.ToString().IndexOf(HireIDFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                        && (item as Hire).ISBN.IndexOf(ISBNFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0);
                }
            }
        }
        private void Filter_TextChanged(object sender, TextChangedEventArgs e)
        {
            CollectionViewSource.GetDefaultView(expired_DataGrid.ItemsSource).Refresh();
        }
        private void setCellsSize()
        {
            foreach (DataGridColumn c in expired_DataGrid.Columns)
            {
                c.Width = new DataGridLength(1.0, DataGridLengthUnitType.Star);
            }
        }

        private void DeleteExpired_Click(object sender, RoutedEventArgs e)
        {
            object item = expired_DataGrid.SelectedItem;
            if (item is null)
            {
                return;
            }
            else
            {
                Main.Library.DeleteHire((Hire)item);
            }
            CollectionViewSource.GetDefaultView(expired_DataGrid.ItemsSource).Refresh();
        }

        private void SendNotification_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                Hire item = (Hire)expired_DataGrid.SelectedItem;
                if (item is null)
                {
                    return;
                }
                else
                {
                    if (item.isExpired is false)
                    {
                        MessageBox.Show("You can't notify not expired hire!");
                    }
                    else
                    {
                        string message = $"You should return this item:\n" +
                                         $"Title: {Main.Library.GetTitle(item.ItemID)}, " +
                                         $"EAN-13: {item.ISBN}\nDelay penalty :{item.Penalty}";
                        Main.Library.AddNotification(message, item.UserID);
                        MessageBox.Show("Notification was sent.");
                    }
                }
            }
            catch
            {
                return;
            }
        }

        private void CheckBox_Changed(object sender, RoutedEventArgs e)
        {
            Filter_TextChanged(sender, e as TextChangedEventArgs);
        }
    }
}
