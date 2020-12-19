using LibraryProject.Classes.LibraryEntity;
using System;
using System.Windows;

namespace LibraryProject.Windows.LibraryMainWindow.PopUpWindows
{
    /// <summary>
    /// Interaction logic for HireWindow.xaml
    /// </summary>
    public partial class HireWindow : Window
    {
        private Entity item{ get; set; }
        public HireWindow(Entity _item)
        {
            item = _item;
            InitializeComponent();
            this.Show();
            setComponents();
        }
        private bool itemIsAvaiable(Entity item)
        {
            if(item.IsRented)
            {
                return false;
            }
            return true;
        }
        private void setIfEnableBorrowing()
        {
            if (item is Book)
            {
                Book book = (Book)item;
                ItemDetails_TextBlock.Text = "Title: " + book.Title + "\nAuthor: " + book.AuthorS;

            }
            else
            {
                Magazine magazine = (Magazine)item;
                ItemDetails_TextBlock.Text = "Title: " + magazine.Title + "\nStock Number: " + magazine.StockNumber;
            }
        }
        private void setIfNotEnableBorrowing()
        {
            DateTime time = Main.Library.GetUntilTime(item.EntityID);
            ItemDetails_TextBlock.Text = $"You can't borrow this item, because it is booked until {time}";
        }
        private void setComponents()
        {
            if(itemIsAvaiable(item))
            {
                setIfEnableBorrowing();
                Reserve_Button.IsEnabled = true;
            }
            else
            {
                Reserve_Button.IsEnabled = false;
                Info_TextBlock.TextDecorations = TextDecorations.Strikethrough;
                setIfNotEnableBorrowing();
            }
        }

        private void ReserveItem_Click(object sender, RoutedEventArgs e)
        {
            Main.Library.HireItem(item);
            MessageBoxResult result;
            if (item is Book)
            {
                Book book = item as Book;
                result = MessageBox.Show($"You have hired a book!" +
                                                          $"\nTitle: {book.Title}" +
                                                          $"\nAuthor: {book.AuthorS}" +
                                                          $"\nISBN: {item.ISBN}", "Information.",
                    MessageBoxButton.OK, MessageBoxImage.None);
            }
            else
            {
                Magazine magazine = item as Magazine;
                result = MessageBox.Show($"You have hired a magazine!" +
                                         $"\nMagazine: {magazine.Title}" +
                                         $"\nStock number: {magazine.StockNumber}" +
                                         $"\nISSN: {magazine.ISBN}", "Information.",
                    MessageBoxButton.OK, MessageBoxImage.None);
            }

            if (result == MessageBoxResult.OK)
            {
                this.Close();
            }
        }
    }
}
