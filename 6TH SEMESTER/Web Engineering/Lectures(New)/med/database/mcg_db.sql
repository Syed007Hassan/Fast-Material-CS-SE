-- phpMyAdmin SQL Dump
-- version 5.1.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 02, 2023 at 07:31 AM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";

--
-- Database: `mcg_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `med_cert_info`
--

CREATE TABLE `med_cert_info` (
  `id` bigint(30) NOT NULL,
  `code` varchar(50) NOT NULL,
  `fullname` text NOT NULL,
  `created_at` datetime NOT NULL DEFAULT current_timestamp(),
  `updated_at` datetime DEFAULT NULL ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `med_cert_info`
--

INSERT INTO `med_cert_info` (`id`, `code`, `fullname`, `created_at`, `updated_at`) VALUES
(1, '20230202-00001', 'Cooper Jr., Mark  D', '2023-02-02 11:35:38', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `med_cert_info_meta`
--

CREATE TABLE `med_cert_info_meta` (
  `id` bigint(30) NOT NULL,
  `med_cert_info_id` bigint(30) NOT NULL,
  `meta_key` text NOT NULL,
  `meta_value` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `med_cert_info_meta`
--

INSERT INTO `med_cert_info_meta` (`id`, `med_cert_info_id`, `meta_key`, `meta_value`) VALUES
(152, 1, 'lastname', 'Cooper'),
(153, 1, 'firstname', 'Mark'),
(154, 1, 'middlename', 'D'),
(155, 1, 'suffix', 'Jr.'),
(156, 1, 'dob', '1997-06-23'),
(157, 1, 'gender', 'Male'),
(158, 1, 'civil_status', 'Married'),
(159, 1, 'contact', '09123654789'),
(160, 1, 'nationality', 'Filipino'),
(161, 1, 'address', 'Sample Address'),
(162, 1, 'diagnostic', 'Flu'),
(163, 1, 'remarks', 'is advising the above individual should take at least 3-4 days to fully recover from his illness.'),
(164, 1, 'doctor_fullname', 'Claire Blake'),
(165, 1, 'doctor_suffix', 'MD');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `med_cert_info`
--
ALTER TABLE `med_cert_info`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `med_cert_info_meta`
--
ALTER TABLE `med_cert_info_meta`
  ADD PRIMARY KEY (`id`),
  ADD KEY `meta_med_cert_info_id_fk` (`med_cert_info_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `med_cert_info`
--
ALTER TABLE `med_cert_info`
  MODIFY `id` bigint(30) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `med_cert_info_meta`
--
ALTER TABLE `med_cert_info_meta`
  MODIFY `id` bigint(30) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=166;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `med_cert_info_meta`
--
ALTER TABLE `med_cert_info_meta`
  ADD CONSTRAINT `meta_med_cert_info_id_fk` FOREIGN KEY (`med_cert_info_id`) REFERENCES `med_cert_info` (`id`) ON DELETE CASCADE ON UPDATE NO ACTION;
COMMIT;
