-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 12, 2023 at 06:10 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `fastmedicos`
--

-- --------------------------------------------------------

--
-- Table structure for table `appoint`
--

CREATE TABLE `appoint` (
  `AName` int(11) NOT NULL,
  `Date` date NOT NULL,
  `PName` varchar(25) NOT NULL,
  `DName` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `appoint`
--

INSERT INTO `appoint` (`AName`, `Date`, `PName`, `DName`) VALUES
(41, '2023-05-03', 'UK1', 'D133'),
(42, '2023-05-03', 'UK1', 'D133'),
(43, '2023-05-03', 'UK1', 'D133'),
(44, '2023-05-03', 'UK1', 'D133');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `appoint`
--
ALTER TABLE `appoint`
  ADD PRIMARY KEY (`AName`),
  ADD KEY `fk_DName_id` (`DName`),
  ADD KEY `fk_PName_id` (`PName`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `appoint`
--
ALTER TABLE `appoint`
  MODIFY `AName` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=45;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `appoint`
--
ALTER TABLE `appoint`
  ADD CONSTRAINT `fk_DName_id` FOREIGN KEY (`DName`) REFERENCES `doctors` (`DName`),
  ADD CONSTRAINT `fk_PName_id` FOREIGN KEY (`PName`) REFERENCES `patients` (`PName`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
