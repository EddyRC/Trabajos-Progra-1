-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 18-11-2018 a las 01:25:51
-- Versión del servidor: 5.7.23
-- Versión de PHP: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `practica2`
--
CREATE DATABASE IF NOT EXISTS `practica2` DEFAULT CHARACTER SET utf8 COLLATE utf8_spanish_ci;
USE `practica2`;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clientes`
--

DROP TABLE IF EXISTS `clientes`;
CREATE TABLE IF NOT EXISTS `clientes` (
  `codcliente` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `apellido` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `tel` varchar(8) COLLATE utf8_spanish_ci DEFAULT NULL,
  PRIMARY KEY (`codcliente`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `clientes`
--

INSERT INTO `clientes` (`codcliente`, `nombre`, `apellido`, `tel`) VALUES
(1, 'Jose', 'Zaldivar', '67564322'),
(2, 'Aminda ', 'Batres', '78254912'),
(3, 'Arnoldo', 'Guzman', '77894568'),
(4, 'Julio', 'Gonzales', '75894587'),
(5, 'Oneyda', 'Velasquez', '74781556'),
(6, 'Gabriel', 'Umaña', '78451425');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cotizaciones`
--

DROP TABLE IF EXISTS `cotizaciones`;
CREATE TABLE IF NOT EXISTS `cotizaciones` (
  `codcotizacion` int(11) NOT NULL AUTO_INCREMENT,
  `codproducto` int(11) NOT NULL,
  `codcliente` int(11) NOT NULL,
  `fecha de cotizacion` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`codcotizacion`)
) ENGINE=MyISAM AUTO_INCREMENT=24 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `cotizaciones`
--

INSERT INTO `cotizaciones` (`codcotizacion`, `codproducto`, `codcliente`, `fecha de cotizacion`) VALUES
(12, 3, 5, '2018-11-17 05:36:55'),
(11, 34, 5, '2018-11-17 05:37:12'),
(23, 2, 8, '2018-11-17 05:37:12');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `productos`
--

DROP TABLE IF EXISTS `productos`;
CREATE TABLE IF NOT EXISTS `productos` (
  `codpro` varchar(8) COLLATE utf8_spanish_ci NOT NULL,
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `precio` float NOT NULL,
  `existencias` int(11) DEFAULT NULL,
  `fechaingreso` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`codpro`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `productos`
--

INSERT INTO `productos` (`codpro`, `nombre`, `precio`, `existencias`, `fechaingreso`) VALUES
('1', 'Televisor Sony', 555, 12, '2018-11-17 05:31:16'),
('2', 'Equipo de sonido AIWA', 434, 11, '2018-11-17 05:31:53'),
('3', 'Licuadoras Oster', 55, 12, '2018-11-17 05:32:15'),
('4', 'Laptop HP 2000', 665, 24, '2018-11-17 05:32:49'),
('5', 'Cafetera', 54, 5, '2018-11-17 05:33:22');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ventas`
--

DROP TABLE IF EXISTS `ventas`;
CREATE TABLE IF NOT EXISTS `ventas` (
  `codventa` int(11) NOT NULL AUTO_INCREMENT,
  `codpro` varchar(8) COLLATE utf8_spanish_ci NOT NULL,
  `cantidad` int(11) NOT NULL,
  `fecha` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `codcliente` int(11) NOT NULL,
  PRIMARY KEY (`codventa`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `ventas`
--

INSERT INTO `ventas` (`codventa`, `codpro`, `cantidad`, `fecha`, `codcliente`) VALUES
(1, '1', 2, '2018-11-16 23:33:57', 1),
(2, '2', 34, '2018-11-16 23:34:17', 2),
(3, '3', 12, '2018-11-16 23:34:39', 3);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
