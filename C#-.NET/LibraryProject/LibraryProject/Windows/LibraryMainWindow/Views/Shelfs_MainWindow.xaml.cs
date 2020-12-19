using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;

using LibraryProject.Classes.LibraryEntity;
using LibraryProject.Classes.UserClass;
using LibraryProject.Windows.LibraryMainWindow.PopUpWindows;
using LibraryProject.Windows.LibraryMainWindow.Views.Admin.ShelfsTab;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin
{
    /// <summary>
    /// Interaction logic for Books_L_MainWindow.xaml
    /// </summary>

    public enum EContentType
    {
        Magazines = 0,
        Books = 1
    }
    public partial class Shelfs_MainWindow : UserControl
    {
        ICollectionView Source { get; set; }

        private EContentType contentType;
        private bool ifCheckBoxChecked { get; set; } = false;
        public Shelfs_MainWindow()
        {
            InitializeComponent();
            if(Main.Library.GetLoggedUser().Role == ERole.Admin)
            {
                Delete_Button.Visibility = Visibility.Visible;
                AddEntity_Button.Visibility = Visibility.Visible;
                HireItem_Button.Visibility = Visibility.Hidden;
            }
            else
            {
                Delete_Button.Visibility = Visibility.Hidden;
                AddEntity_Button.Visibility = Visibility.Hidden;
                HireItem_Button.Visibility = Visibility.Visible;
            }

            contentType = EContentType.Books;

            setCellsSize(books_DataGrid);
            setCellsSize(magazines_DataGrid);

            SetComboBox();
            SetListData();
        }
        public void setCellsSize(DataGrid _dg)
        {
            foreach (DataGridColumn c in _dg.Columns)
            {
                c.Width = new DataGridLength(1.0, DataGridLengthUnitType.Star);
            }

        }
        private void SetComboBox()
        {
            List<Genre> genres = new List<Genre>(Main.Library.GetGenres());
            genres.Insert(0, new Genre("Select Genre", 0));
            Genres_ComboBox.ItemsSource = genres;
            Genres_ComboBox.DisplayMemberPath = "Name";
            Genres_ComboBox.SelectedValuePath = "GenreID";
            Genres_ComboBox.SelectedIndex = 0;
            genres = null;
        }
        private void SetListData()
        {
            books_DataGrid.ItemsSource = Main.Library.GetEntities().Where(Item => Item is Book);
            magazines_DataGrid.ItemsSource = Main.Library.GetEntities().Where(Item => Item is Magazine);

            Source = CollectionViewSource.GetDefaultView(books_DataGrid.ItemsSource);
            Source.Filter = BooksFilter;
        }
        private void ChangeContent_Click(object sender, RoutedEventArgs e)
        {
            Source = null;
            if (contentType == EContentType.Books)
            {
                Source = CollectionViewSource.GetDefaultView(magazines_DataGrid.ItemsSource);
                Source.Filter = MagazineFilter;
                contentType = EContentType.Magazines;
                SetDataGridView();
            }
            else
            {
                Source = CollectionViewSource.GetDefaultView(books_DataGrid.ItemsSource);
                Source.Filter = BooksFilter;
                contentType = EContentType.Books;
                SetDataGridView();
            }
        }
        private void SetDataGridView()
        {
            if (contentType == EContentType.Books)
            {
                magazines_DataGrid.Visibility = Visibility.Hidden;
                books_DataGrid.Visibility = Visibility.Visible;

                ChangeContent_Button.Content = "Show Magazines";
                Changable_Label.Content = "Search Author:";
            }
            else
            {
                books_DataGrid.Visibility = Visibility.Hidden;
                magazines_DataGrid.Visibility = Visibility.Visible;

                ChangeContent_Button.Content = "Show Books";
                Changable_Label.Content = "Search Stock Number:";
            }
            ChangableFilter_TextBox.Text = "";
            TitleFilter_TextBox.Text = "";
        }
        private uint GenresComboboxSelectedItem()
        {
            return Main.Library.GetGenreID(Genres_ComboBox.Text);               
        }
        private bool BooksFilter(object item)
        {
            if (String.IsNullOrEmpty(TitleFilter_TextBox.Text)
                && String.IsNullOrEmpty(ChangableFilter_TextBox.Text)
                && ifCheckBoxChecked is false
                && Genres_ComboBox.SelectedIndex == 0)
            {
                return true;
            }
            else
            {
                if (ifCheckBoxChecked)
                {
                    if (Genres_ComboBox.SelectedIndex != 0)
                    {
                        return ((item as Book).Title.IndexOf(TitleFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                          && (item as Book).AuthorS.IndexOf(ChangableFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                          && (item as Book).IsRented is false && ((item as Book).GenreID == GenresComboboxSelectedItem()));
                    }
                    else
                    {
                        return ((item as Book).Title.IndexOf(TitleFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                          && (item as Book).AuthorS.IndexOf(ChangableFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                          && (item as Book).IsRented is false);
                    }
                }
                else
                {
                    if (Genres_ComboBox.SelectedIndex != 0)
                    {
                        return ((item as Book).Title.IndexOf(TitleFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                      && (item as Book).AuthorS.IndexOf(ChangableFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                      && ((item as Book).GenreID == Genres_ComboBox.SelectedIndex));
                    }
                    else
                    {
                        return ((item as Book).Title.IndexOf(TitleFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                       && (item as Book).AuthorS.IndexOf(ChangableFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0);
                    }
                }
            }
        }
        private void Filter_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (contentType == EContentType.Books)
            {
                CollectionViewSource.GetDefaultView(books_DataGrid.ItemsSource).Refresh();
            }
            else
            {
                CollectionViewSource.GetDefaultView(magazines_DataGrid.ItemsSource).Refresh();
            }
        }
        private bool MagazineFilter(object item)
        {
            if (String.IsNullOrEmpty(TitleFilter_TextBox.Text)
                && String.IsNullOrEmpty(ChangableFilter_TextBox.Text)
                && ifCheckBoxChecked is false)
            {
                return true;
            }
            else
            {
                if (ifCheckBoxChecked)
                {
                    return ((item as Magazine).Title.IndexOf(TitleFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                      && (item as Magazine).StockNumber.ToString().IndexOf(ChangableFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                      && (item as Magazine).IsRented is false);
                }
                else
                {
                    return ((item as Magazine).Title.IndexOf(TitleFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0
                            && (item as Magazine).StockNumber.ToString().IndexOf(ChangableFilter_TextBox.Text, StringComparison.OrdinalIgnoreCase) >= 0);
                }
            }
        }
        private void CheckBox_Changed(object sender, RoutedEventArgs e)
        {
            CheckBox checkBox = sender as CheckBox;
            if (checkBox.IsChecked is true)
            {
                ifCheckBoxChecked = true;
            }
            else
            {
                ifCheckBoxChecked = false;
            }
            Filter_TextChanged(sender, e as TextChangedEventArgs);
        }
        private void GenresComboBox_Changed(object sender, SelectionChangedEventArgs e)
        {
            if (Genres_ComboBox.SelectedIndex == 0)
            {
                Genres_ComboBox.Foreground = Brushes.Black;
            }
            else
            {
                Genres_ComboBox.Foreground = Brushes.Red;
            }
            if (books_DataGrid.ItemsSource != null)
            {
                CollectionViewSource.GetDefaultView(books_DataGrid.ItemsSource).Refresh();
            }
        }
        private void DeleteButton_Click(object sender, RoutedEventArgs e)
        {
            if(contentType == EContentType.Books)
            {
                Book book = (Book)books_DataGrid.SelectedItem;
                MessageBoxResult messageBoxResult = MessageBox.Show($"Are you sure to delete this book?\n Book title:{book.Title}\nBook ISBN:{book.ISBN}", "Deleting book!",
                                                                    MessageBoxButton.YesNo, MessageBoxImage.Warning, MessageBoxResult.No);
                if(messageBoxResult == MessageBoxResult.Yes)
                {
                    Main.Library.DeleteEntity(book.EntityID);
                }
                SetListData();
                CollectionViewSource.GetDefaultView(books_DataGrid.ItemsSource).Refresh();
            }
            else 
            {
                Magazine magazine = (Magazine)magazines_DataGrid.SelectedItem;
                MessageBoxResult messageBoxResult = MessageBox.Show($"Are you sure to delete this magazine?\n Magazine title:{magazine.Title}\nBook ISSN:{magazine.ISBN}", "Deleting book!",
                                                                    MessageBoxButton.YesNo, MessageBoxImage.Warning, MessageBoxResult.No);
                if (messageBoxResult == MessageBoxResult.Yes)
                {
                    Main.Library.DeleteEntity(magazine.EntityID);
                }
                SetListData();
                CollectionViewSource.GetDefaultView(magazines_DataGrid.ItemsSource).Refresh();
            }
        }
        private void AddEntity_Click(object sender, RoutedEventArgs e)
        {
            if (Application.Current.Windows.OfType<AddEntity>().Any())
            {
                return;
            }
            else
            {
                AddEntity addEntity = new AddEntity();
            }
        }
        private void HireItem_Click(object sender, RoutedEventArgs e)
        {
            Entity item;
            if(contentType == EContentType.Books)
            {
                item = (Entity)books_DataGrid.SelectedItem;
            }
            else
            {
                item = (Entity)magazines_DataGrid.SelectedItem;
            }

            if (item is null)
            {
                return;
            }
            else
            {
                HireWindow hireWindow = new HireWindow(item);
            }
        }
        private void Refresh_Click(object sender, RoutedEventArgs e)
        {
            if (contentType == EContentType.Books)
            {
                books_DataGrid.ItemsSource = null;
                books_DataGrid.ItemsSource = Main.Library.GetEntities().Where(Item => Item is Book);
                CollectionViewSource.GetDefaultView(books_DataGrid.ItemsSource).Refresh();
            }
            else
            {
                magazines_DataGrid.ItemsSource = null;
                magazines_DataGrid.ItemsSource = Main.Library.GetEntities().Where(Item => Item is Magazine);
                CollectionViewSource.GetDefaultView(magazines_DataGrid.ItemsSource).Refresh();

            }
        }
    }

}
