   M S B A M L   `   `   `  ����I  ELibraryProject, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null}Cclr-namespace:LibraryProject.Windows.LibraryMainWindow.PopUpWindows5LibraryProject.Windows.LibraryMainWindow.PopUpWindows  5   	   N    HLibraryProject.Windows.LibraryMainWindow.PopUpWindows.NotificationWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   UlocalCclr-namespace:LibraryProject.Windows.LibraryMainWindow.PopUpWindows     5   	     � Title$  NotificationWindow��5   	   $	��406��6$   $	��402��61    � 
ResizeMode$ NoResize=�5	   	    � WindowStartupLocation$ CenterScreen=�5
   	    � 	Resources 5         Message �� Path��%^   &	        �� 5   
   .R�5      �� $
��Wrap=�6   ��6,   �� $ Message�5      5      .��5      �� .+�5   
   �� $��Notifications��6   $��20(�6)   $��Center=�67   $��	Underline{�6T   &   System.Windows.Controls.DataGrid  5   
   -   5          Name$ Messages_DataGrid��5      $��3q�6      AutoGenerateColumns .  $	��300��6U   $	��300��6b   $   HorizontalScrollBarVisibility$ Disabled=�6r      
IsReadOnly . 	   Columns	 5      0  *System.Windows.Controls.DataGridTextColumn  5      ,  &System.Windows.Controls.DataGridColumn
   Header$

 Time��6%   1  +System.Windows.Controls.DataGridBoundColumn   Binding 63   �� $
 time�4  .System.Windows.Controls.DataGridTemplateColumn  5      $
 Message��6)      CellTemplate# [  6:   5      5      � 5   
    � ColumnDefinitions 5      �� 5      $��* �6#   �� 5      $��* �6#   .+�5       �� -   5        $��Clear Messages��5       $��0��6.   6>   �� 5!      -   5        $��Close��5!      $��1��6%   65   5"      5&      5'      